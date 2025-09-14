#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) 
{
    if (argc != 2) 
	{
        std::cerr << "Error: Please provide argument.\n";
        return 1;
    }

    const std::string expr = argv[1];
    RPN rpn;
    try 
	{
        double result = rpn.evaluate(expr);
        std::cout << result << "\n";
    } 
	catch (const std::exception& e) 
	{
        std::cerr << e.what() << "\n";
        return 1;
    }
}