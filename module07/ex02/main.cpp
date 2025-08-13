#include <iostream>
#include "Array.hpp"

int main() 
{
    std::cout << "Creating Array of size 5 using constructor\n";
    Array<int> arr1(5);
    for (std::size_t i = 0; i < arr1.size(); ++i) 
    {
        std::cout << "arr1[" << i << "] = " << arr1[i] << "\n";
    }
    
    /*  int *ab = new int();
        std::cout << "Array a contents ab: " << *ab << "\n";
     */

    std::cout << "\nCopy constructor and assignment operator and subscript [] operator\n";
    Array<int> a(5);
    for (std::size_t i = 0; i < a.size(); ++i) 
    {
        a[i] = static_cast<int>(i * 10);
    }
    Array<int> b = a;
    std::cout << "a[0]: " << a[0] << ", b[0]: " << b[0] << "\n";
	
    b[0] = 999;
	std::cout << "After item at index 0 is changed in array b\n";
    std::cout << "a[0]: " << a[0] << ", b[0]: " << b[0] << "\n";

    std::cout << "\nTesting out-of-bounds access\n";
    try 
    {
        std::cout << a[10] << "\n";
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTesting default constructor\n";
    Array<int> c;
    std::cout << "Size of default-constructed array: " << c.size() << "\n";

    std::cout << "\nTesting assignment operator\n";
    Array<int> d(3);
    std::cout << "d[0]: " << d[0] << ", d[1]: " << d[1] << ", d[2]: " << d[2] << "\n";
    d[0] = 42;
    d[1] = 84;
    d[2] = 126;
    std::cout << "After assigning values to d\n";
    std::cout << "d[0]: " << d[0] << ", d[1]: " << d[1] << ", d[2]: " << d[2] << "\n";

    std::cout << "Copying d to c with assignment operator\n";
    c = d;
    std::cout << "d[0]: " << d[0] << ", d[1]: " << d[1] << ", d[2]: " << d[2] << "\n";
    std::cout << "c[0]: " << c[0] << ", c[1]: " << c[1] << ", c[2]: " << c[2] << "\n";

    std::cout << "\nTesting copy constructor with const Array\n";
    const Array<int> e = d;
    std::cout << "e[0]: " << e[0] << ", e[1]: " << e[1] << ", e[2]: " << e[2] << "\n";

    std::cout << "\nTesting Array with different types (string)\n";
    Array<std::string> f(3);
    f[0] = "Hello";
    f[1] = "World";
    f[2] = "!";
    for (std::size_t i = 0; i < f.size(); ++i) 
    {
        std::cout << "f[" << i << "]: " << f[i] << "\n";
    }

    std::cout << "\nTesting Array with large size\n";
    Array<int> g(1000);
    for (std::size_t i = 0; i < g.size(); ++i) 
    {
        g[i] = static_cast<int>(i);
    }
    std::cout << "g[999]: " << g[999] << "\n";
}
