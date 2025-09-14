#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) 
{
    if (argc < 2) 
	{
        std::cerr << "Error: Please provide collection of numbers to sort\n";
        return 1;
    }
    try 
	{
        std::vector<std::string> args(argv + 1, argv + argc);
        PmergeMe sorter(args);

		std::cout << "Before: ";
		std::cout << sorter.getElements();
		std::cout << "\n";
        sorter.performSorting();
		std::cout << "After: ";
		std::cout << sorter.getElements();
		std::cout << "\n";
    } 
	catch (const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
}