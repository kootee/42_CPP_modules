/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 13:36:33 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void runTest(const Fixed& num1, const Fixed& num2) 
{
    // Addition
    Fixed sum = num1.operator+(num2);
    std::cout << num1.toFloat() << " + " << num2.toFloat() << " = " << sum.toFloat() << std::endl;

    // Subtraction
    Fixed diff = num1.operator-(num2);
    std::cout << num1.toFloat() << " - " << num2.toFloat() << " = " << diff.toFloat() << std::endl;

    // Multiplication
    Fixed prod = num1.operator*(num2);
    std::cout << num1.toFloat() << " * " << num2.toFloat() << " = " << prod.toFloat() << std::endl;

    // Division
    if (num2.toFloat() != 0) { // Prevent division by zero
        Fixed quot = num1.operator/(num2);
        std::cout << num1.toFloat() << " / " << num2.toFloat() << " = " << quot.toFloat() << std::endl;
    } else {
        std::cout << "Division by zero is undefined for " << num1.toFloat() << " / " << num2.toFloat() << std::endl;
    }
} 

int main(void)
{
    {
        Fixed a;
        Fixed const b(Fixed(5.05f).operator*(Fixed(2)));
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    {
        Fixed a(2);
        Fixed b(3.5f);

        // Test arithmetic operations
        Fixed sum = a + b;
        Fixed diff = a - b;
        Fixed prod = a * b;
        Fixed quot = a / b;

        std::cout << "a + b = " << sum << std::endl;
        std::cout << "a - b = " << diff << std::endl;
        std::cout << "a * b = " << prod << std::endl;
        std::cout << "a / b = " << quot << std::endl;
    }
    {
        Fixed a(2);           // Represents 2.0
        Fixed b(3.5f);       // Represents 3.5
        Fixed c(0.5f);       // Represents 0.5
        Fixed d(1);          // Represents 1.0
        Fixed e(-1.0f);      // Represents -1.0
        Fixed f(0);          // Represents 0.0

        // Addition
        Fixed sum = a + b;
        std::cout << "a + b = " << sum.toFloat() << " (Expected: 5.5)" << std::endl;

        // Subtraction
        Fixed diff = a - b;
        std::cout << "a - b = " << diff.toFloat() << " (Expected: -1.5)" << std::endl;

        // Multiplication
        Fixed prod = a * b;
        std::cout << "a * b = " << prod.toFloat() << " (Expected: 7.0)" << std::endl;

        // Division
        Fixed quot = b / a;
        std::cout << "b / a = " << quot.toFloat() << " (Expected: 1.75)" << std::endl;

        // More tests with zero
        Fixed zero = a * f;  // 2.0 * 0.0 = 0.0
        std::cout << "a * f = " << zero.toFloat() << " (Expected: 0.0)" << std::endl;

        // Division by a negative number
        Fixed negDiv = b / e; // 3.5 / -1.0 = -3.5
        std::cout << "b / e = " << negDiv.toFloat() << " (Expected: -3.5)" << std::endl;

        // Division by zero (this should be handled gracefully, ensure it doesn't crash)
        try {
            Fixed divByZero = a / f; // 2.0 / 0.0
            std::cout << "a / f = " << divByZero.toFloat() << " (Expected: Exception or undefined)" << std::endl;
        } catch (...) {
            std::cout << "Caught division by zero exception!" << std::endl;
        }

        // Additional cases
        Fixed mixed = d.operator+(c);   // d + c OR 1.0 + 0.5 = 1.5
        std::cout << "d + c = " << mixed.toFloat() << " (Expected: 1.5)" << std::endl;

        Fixed mixedProd = c * b; // 0.5 * 3.5 = 1.75
        std::cout << "c * b = " << mixedProd.toFloat() << " (Expected: 1.75)" << std::endl;

        Fixed mixedDiff = d - c; // 1.0 - 0.5 = 0.5
        std::cout << "d - c = " << mixedDiff.toFloat() << " (Expected: 0.5)" << std::endl;
    }
    {
        
    }
    
    float input1;
    float input2;
    
    while (true)
    {
        std::cout << "Input first (float or int) number:"; 
        std::cin >> input1;
        std::cout << "Input first (float or int) number:"; 
        std::cin >> input2;

        Fixed fixed1(input1);
        Fixed fixed2(input2);
        
        runTest(fixed1, fixed2);
    }
    return 0;
}
