#include <iostream>
#include <exception>

/*  a = address of array
    b = length of array
    c = function to be implemented on each object */

template <typename T> 
void iter(T *a, size_t len, void(*f)()) 
{
    for (size_t i = 0; i < len; i++) 
    {
        if (i > a.size())
            throw std::exception();
        else
            f(a[i]);
    }
}