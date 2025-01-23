#include "iter.hpp"
#include <iostream>

/* template <int > void power_of_two(T &num)
{
    num = num * num;
} */

void    power_of_two(int &i)
{
    i = i * i;
}

void    add_t_string(std::string &str)
{
    str = str + " Hello";
}

int main()
{
    int arr1[] = { 10, 20, 15, 12 };

    std::string names[] = { "123", "234", "345" };

    ::iter<int*, size_t, void(*)(&int)>(arr1, 4, &power_of_two); 
    // Second template parameter
    // to arrMin must be a
    // constant
    // std::cout << power_of_two<int, 10000>(arr1, n1) << std::endl;
    // std::cout << power_of_two<char, 256>(arr2, n2);
  
    return 0;
}