#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
    this->_db = other._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other)
        this->_db = other._db;
    return *this;
}

static bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
        return false;
    }

    int year;
	int month;
	int day;

    char dash1;
	char dash2;
	
    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day)
		|| dash1 != '-' 
		|| dash2 != '-') 
	{
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) 
        return false;
		
    return true;
}

static bool isValidValue(const std::string& value)
{
    try
	{
        float val = std::stof(value);
        if (val < 0 || val > 1000)
		{
            return false;
        }
    } catch (const std::exception&) {
        return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& csvFilePath)
{
    std::ifstream file(csvFilePath);
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open database file.");

    std::string line;
    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        std::string date;
		std::string priceStr;

        if (std::getline(iss, date, ',') && std::getline(iss, priceStr))
		{
            if (isValidDate(date))
			{
                try 
				{
                    float price = std::stof(priceStr);
                    _db[date] = price;
                } catch (const std::exception&) {
                    continue;
                }
            }
        }
    }
    file.close();
}

float BitcoinExchange::calculateValue(const std::string& date, float amount) const
{
    auto it = _db.lower_bound(date);

    if (it == _db.end() || it->first > date)
	{
        if (it == _db.begin())
            throw std::runtime_error("No price data available for the given date.");
        --it;
    }
    return it->second * amount;
}

void BitcoinExchange::processInputFile(const std::string& inputFilePath) const 
{
    std::ifstream file(inputFilePath);
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open input file.");

    std::string line;
    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
		{
            date = date.substr(0, date.find_last_not_of(" \t") + 1);
            valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));

            if (!isValidDate(date))
                continue;

            if (!isValidValue(valueStr))
			{
                try {
                    float value = std::stof(valueStr);
                    if (value < 0)
                        std::cout << "Error: not a positive number.\n";
					else if (value > 1000)
                        std::cout << "Error: too large a number\n";
                } catch (const std::exception&) {
                    std::cout << "Error: bad input => " << line << "\n";
                }
                continue;
            }

            try {
                float value = std::stof(valueStr);
                float result = calculateValue(date, value);
                std::cout << date << " => " << value << " = " << result << "\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else
            std::cout << "Error: bad input => " << line << "\n";
    }
    file.close();
}