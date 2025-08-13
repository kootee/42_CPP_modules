#include <iostream>
#include <exception>

template <typename T, size_t N, void(*func)(T &i)>
void iter(T(&a)[N], size_t len, void(*f)(T &i))
{
    if (len != N) 
        throw std::out_of_range("Invalid length");

    for (size_t i = 0; i < len; i++) 
    {
        try 
        {
            f(a[i]);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << "\n";
            return;
        }
    }
}