#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    try
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "Found in vector: " << *easyfind(vec, 3) << "\n";

        std::list<int> lst = {10, 20, 30, 40, 50};
        std::cout << "Found in list: " << *easyfind(lst, 20) << "\n";

        std::cout << "Trying to find 100 in vector..." << "\n";
        easyfind(vec, 100);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    try
    {
        std::vector<int> emptyVec;
        std::cout << "Trying to find in an empty vector..." << "\n";
        easyfind(emptyVec, 1);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    try
    {
        std::deque<int> deq = {5, 10, 15, 20};
        std::cout << "Found in deque: " << *easyfind(deq, 15) << "\n";

        std::vector<int> dupVec = {1, 2, 3, 3, 4};
        std::cout << "Looking for first occurrence: " << *easyfind(dupVec, 3) << "\n";

        std::list<int> negList = {-10, -20, -30, -40};
        std::cout << "Found in list with negative numbers: " << *easyfind(negList, -30) << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}