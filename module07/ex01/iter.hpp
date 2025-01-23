#include <iostream>
#include <exception>

/*  
    template <template parameter> (type returned by function) <T>
    the last T means that the functin's template param is also
    the class template param. Declaring class function templates:
    ---> template <class T> T ClassName<T>::functionName()

    This is the syntax used in the class template specialization:
    template <> class mycontainer <char> { ... };
*/

template <typename T, size_t N, void(*func)> 
void iter(T *a, size_t len, void(*f)(int &i)) 
{
    for (size_t i = 0; i < len; i++) 
    {
        if (i > a.size())
            throw std::exception();
        else
            f(a[i]);
    }
}