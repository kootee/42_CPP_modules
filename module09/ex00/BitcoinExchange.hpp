#pragma once

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _db;

public:
    // Canonical form
    BitcoinExchange();
    ~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& csvFilePath);
    void processInputFile(const std::string& inputFilePath) const;
	float calculateValue(const std::string& date, float amount) const;
};