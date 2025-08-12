#include <iostream>
#include "Array.hpp"

int main() 
{
    // Test 1: Basic functionality
    Array<int> a(5);
    for (std::size_t i = 0; i < a.size(); ++i) 
    {
        a[i] = static_cast<int>(i * 10);
    }

    Array<int> b = a; // Test copy constructor
    std::cout << "a[0]: " << a[0] << ", b[0]: " << b[0] << "\n";
	
    b[0] = 999;       // Modify b to ensure deep copy
	std::cout << "After item at index 0 is changed in array b\n";
    std::cout << "a[0]: " << a[0] << ", b[0]: " << b[0] << "\n";

    // Test 2: Out-of-bounds access
    try 
    {
        std::cout << a[10] << "\n";
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    // Test 3: Default constructor
    Array<int> c;
    std::cout << "Size of default-constructed array: " << c.size() << "\n";

    // Test 4: Assignment operator
    Array<int> d(3);
    d[0] = 42;
    d[1] = 84;
    d[2] = 126;

    c = d;
    std::cout << "d[0]: " << d[0] << ", d[1]: " << d[1] << ", d[2]: " << d[2] << "\n";
    std::cout << "c[0]: " << c[0] << ", c[1]: " << c[1] << ", c[2]: " << c[2] << "\n";

    // Test 5: Const correctness
    const Array<int> e = d;
    std::cout << "e[0]: " << e[0] << ", e[1]: " << e[1] << ", e[2]: " << e[2] << "\n";

    // Test 6: Array of strings
    Array<std::string> f(3);
    f[0] = "Hello";
    f[1] = "World";
    f[2] = "!";
    for (std::size_t i = 0; i < f.size(); ++i) 
    {
        std::cout << "f[" << i << "]: " << f[i] << "\n";
    }

    // Test 7: Large array
    Array<int> g(1000);
    for (std::size_t i = 0; i < g.size(); ++i) 
    {
        g[i] = static_cast<int>(i);
    }
    std::cout << "g[999]: " << g[999] << "\n";
	
}
