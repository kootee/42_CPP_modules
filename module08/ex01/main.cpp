#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "\n=== Testing Basic Span ===" << std::endl;
    Span sp1 = Span(5);

    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    try 
    {
        std::cout << "Adding one too many..." << std::endl;
        sp1.addNumber(1);
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Exception: " << e.what();
    }

    std::cout << "\n=== Testing Another Basic Span ===" << std::endl;
    try 
    {
        Span span(10);
        
        std::vector<int> numbers = {10, 2045, 30, 40, 505894, 4523, 756, 1234, 5678, 91011};
    
        span.addNumberRange(numbers.begin() + 1, numbers.begin() + 4);
    
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Exception: " << e.what();
    }

    std::cout << "\n=== Testing Span with 0 capacity ===" << std::endl;
    Span sp(0);
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what();
    }
    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what();
    }
    try
    {
        sp.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what();
    }
    

    std::cout << "\n=== Testing with 10,000 elements ===" << std::endl;
    
    try
    {        
        Span megaSpan(10000);
        
        std::vector<int> largeNumbers;
        largeNumbers.reserve(10000);
        
        for (int i = 1; i <= 10000; ++i)
            largeNumbers.emplace_back(i);
        
        megaSpan.addNumberRange(largeNumbers.begin(), largeNumbers.end());
        
        std::cout << "Added 10,000 elements" << std::endl;
        std::cout << "Shortest span: " << megaSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << megaSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}