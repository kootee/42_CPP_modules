#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cout << "Error: Please provide input file.\n";
        return 1;
    }
	try
	{
		BitcoinExchange btcExchange;
        btcExchange.loadDatabase("data.csv");

		const std::string inputFile = argv[1];
		btcExchange.processInputFile(inputFile);
    } 
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}