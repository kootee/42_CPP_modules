#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime> 
#include <iostream>

Base* generate(void)
{
    int classType = std::rand() % 3;
    switch (classType)
    {
        case 0:
            std::cout << "Instance of A generated\n";
            return new A();
        case 1:
            std::cout << "Instance of B generated\n";
            return new B();
        case 2:
            std::cout << "Instance of C generated\n";
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is: C\n";
    else
        std::cout << "Type is: Unknown\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A\n";
    }
    catch (const std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B\n";
    }
    catch (const std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C\n";
    }
    catch (const std::bad_cast&) {}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	std::cout << "Testing generate and identify functions:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test no " << i << ":\n";
		Base* randomBase = generate();
	
		std::cout << "Identifying using pointer:\n";
		identify(randomBase);
	
		std::cout << "Identifying using reference:\n";
		identify(*randomBase);
	
		delete randomBase;
	}
}