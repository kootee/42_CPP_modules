#include <iostream>
#include <stdexcept>
#include "iter.hpp"  // Include the header for the template function

// Function that multiplies each element by 2
void multiplyByTwo(int &i) {
    i *= 2;
}

// Function that sums all elements of the array
void sumArray(int &i) {
    static int sum = 0;
    sum += i;
    i = sum;
}

// Function that squares each element of the array
void squareArray(int &i) {
    i *= i;
}

// Function that decrements each element by 1
void decrementArray(int &i) {
    i--;
}

// Function that adds "Hello" to each element of a string array
void addHello(std::string &s) {
    s = "Hello " + s;
}

int main() {
    // Test 1: Multiply each element by 2
    std::cout << "Test 1: Multiply by two\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";

    int arr1[5] = {1, 2, 3, 4, 5};
    try {
        iter<int, 5, multiplyByTwo>(arr1, 5, multiplyByTwo);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr1[i] << " ";  // Expected output: 2 4 6 8 10
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test 2: Sum all elements of the array (accumulating sum)
    std::cout << "\nTest 2: Sum the elements\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr2[5] = {1, 2, 3, 4, 5};
    try {
        iter<int, 5, sumArray>(arr2, 5, sumArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr2[i] << " ";  // Expected output: 1 3 6 10 15
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test 3: Square each element in the array
    std::cout << "\nTest 3: Square each element\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr3[5] = {1, 2, 3, 4, 5};
    try {
        iter<int, 5, squareArray>(arr3, 5, squareArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr3[i] << " ";  // Expected output: 1 4 9 16 25
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test 4: Decrement each element by 1
    std::cout << "\nTest 4: Decrement each element by 1\n";
    std::cout << "Test array: 1, 2, 3, 4, 5\n";
    int arr4[5] = {1, 2, 3, 4, 5};
    try {
        iter<int, 5, decrementArray>(arr4, 5, decrementArray);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr4[i] << " ";  // Expected output: 0 1 2 3 4
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test 5: Out of range exception
    std::cout << "\nTest 5: Out of range exception\n";
    int arr5[5] = {1, 2, 3, 4, 5};
    try 
    {
        iter<int, 5, multiplyByTwo>(arr5, 50, multiplyByTwo);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) {
            std::cout << arr5[i] << " ";  // Expected output: 2 4 6 8 10
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test 6: Adding "Hello" to each element (string array)
    std::cout << "\nTest 6: Adding 'Hello' to each element (string array)\n";
    std::string arr6[5] = {"World", "C++", "is", "great", "!!!"};
    try {
        iter<std::string, 5, addHello>(arr6, 5, addHello);
        std::cout << "Result\n";
        for (int i = 0; i < 5; i++) 
        {
            std::cout << arr6[i] << " ";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    std::cout << "\n";
    return 0;
}
