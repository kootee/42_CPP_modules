#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) 
{
    if (argc != 2) {
        std::cout << "Error: Please provide input file.\n";
        return 1;
    }

    const std::string inputFile = argv[1];
	try 
	{
        BitcoinExchange btcExchange;
        btcExchange.loadDatabase("data.csv");
		btcExchange.processInputFile(inputFile);
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}