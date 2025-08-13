#include <iostream>
#include <stdexcept>
#include "iter.hpp"

void multiplyByTwo(int &i) 
{
    i *= 2;
}

void sumArray(int &i) 
{
    static int sum = 0;
    sum += i;
    i = sum;
}

void squareArray(int &i) 
{
    i *= i;
}

void decrementArray(int &i) 
{
    i--;
}

void addHello(std::string &s) 
{
    s = "Hello " + s;
}

void addAsterisk(std::string &s) 
{
    s = s + "*";
}

int main() 
{
    std::cout << "Test 1: Multiply by two\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    try 
    {
        iter<int, 10, multiplyByTwo>(arr1, 10, multiplyByTwo);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr1[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 2: Sum the elements\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr2[6] = {1, 2, 3, 4, 5, 6};
    try 
    {
        iter<int, 6, sumArray>(arr2, 6, sumArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr2[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 3: Square each element\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr3[5] = {1, 2, 3, 4, 5};
    try 
    {
        iter<int, 5, squareArray>(arr3, 5, squareArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr3[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 4: Decrement each element by 1\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr4[5] = {1, 2, 3, 4, 5};
    try 
    {
        iter<int, 5, decrementArray>(arr4, 5, decrementArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr4[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 5: Incorrect length (too long)\n";
    int arr5[5] = {1, 2, 3, 4, 5};
    try 
    {
        iter<int, 5, multiplyByTwo>(arr5, 700, multiplyByTwo);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr5[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 6: Adding 'Hello' to each element (string array)\n";
    std::string arr6[5] = {"World", "C++", "is", "great", "!!!"};
    try 
    {
        iter<std::string, 5, addHello>(arr6, 5, addHello);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) 
        {
            std::cout << arr6[i] << " ";
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    std::cout << "\n";

    std::cout << "\nTest 7: Incorrect array length (too short)\n";
    std::string arr7[5] = {"World", "C++", "is", "great", "!!!"};
    try 
    {
        iter<std::string, 5, addAsterisk>(arr7, 2, addAsterisk);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) 
        {
            std::cout << arr7[i] << " ";
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\nTest 8: 0 as length\n";
    std::string arr8[1] = {""};
    try 
    {
        iter<std::string, 1, addAsterisk>(arr8, 0, addAsterisk);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
}
