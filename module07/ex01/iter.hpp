#include <iostream>
#include <exception>

template <typename T, size_t N, void(*func)(T &i)>
void iter(T(&a)[N])
{
    for (size_t i = 0; i < N; i++) 
    {
        try 
        {
            func(a[i]);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << "\n";
            return;
        }
    }
}