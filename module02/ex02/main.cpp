/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 09:39:59 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void runTest(const Fixed& num1, const Fixed& num2) 
{
	std::cout << num1.toFloat() << " " << num2.toFloat() << std::endl;
	
	// Addition
	Fixed sum = num1.operator+(num2);
	std::cout << num1.toFloat() << " + " << num2.toFloat() << " = " 
	<< sum.toFloat() << std::endl;

	// Subtraction
	Fixed diff = num1.operator-(num2);
	std::cout << num1.toFloat() << " - " << num2.toFloat() << " = " 
	<< diff.toFloat() << std::endl;

	// Multiplication
	Fixed prod = num1.operator*(num2);
	std::cout << num1.toFloat() << " * " << num2.toFloat() << " = " 
	<< prod.toFloat() << std::endl;

	// Division
	if (num2.toFloat() != 0) { // Prevent division by zero
		Fixed quot = num1.operator/(num2);
		std::cout << num1.toFloat() << " / " << num2.toFloat() << " = " 
		<< quot.toFloat() << std::endl;
	} else {
		std::cout << "Division by zero is undefined for " 
		<< num1.toFloat() << " / " << num2.toFloat() 
		<< std::endl;
	}

	std::cout << "Max of num1 and num2: " << Fixed::max(num1, num2) << std::endl;
	std::cout << "Min of num1 and num2: " << Fixed::min(num1, num2) << std::endl;
} 

int main(void)
{
	{
		std::cout << "Test Comparison Operators: " << std::endl;

		Fixed a;
		Fixed const b(Fixed(5.05f).operator*(Fixed(2))); // b = 10.1
		Fixed const c(10.1f);
		Fixed const d(5.0f);
		Fixed e(10.1f);
		
		std::cout << a << " < " << b << ": " << ((a < b) ? "true" : "false") << std::endl; // Expected true
		std::cout << a << " > " << b << ": " << ((a > b) ? "true" : "false") << std::endl; // Expected false
		std::cout << a << " <= " << b << ": " << ((a <= b) ? "true" : "false") << std::endl; // Expected true
		std::cout << a << " >= " << b << ": " << ((a >= b) ? "true" : "false") << std::endl; // Expected false

		std::cout << b << " < " << c << ": " << ((b < c) ? "true" : "false") << std::endl; // Expected false
		std::cout << b << " > " << c << ": " << ((b > c) ? "true" : "false") << std::endl; // Expected false
		std::cout << b << " <= " << c << ": " << ((b <= c) ? "true" : "false") << std::endl; // Expected true
		std::cout << b << " >= " << c << ": " << ((b >= c) ? "true" : "false") << std::endl; // Expected true

		std::cout << d << " < " << b << ": " << ((d < b) ? "true" : "false") << std::endl; // Expected true
		std::cout << d << " > " << b << ": " << ((d > b) ? "true" : "false") << std::endl; // Expected false
		std::cout << d << " <= " << b << ": " << ((d <= b) ? "true" : "false") << std::endl; // Expected true
		std::cout << d << " >= " << b << ": " << ((d >= b) ? "true" : "false") << std::endl; // Expected false

		std::cout << c << " < " << d << ": " << ((c < d) ? "true" : "false") << std::endl; // Expected false
		std::cout << c << " > " << d << ": " << ((c > d) ? "true" : "false") << std::endl; // Expected true
		std::cout << c << " <= " << d << ": " << ((c <= d) ? "true" : "false") << std::endl; // Expected false
		std::cout << c << " >= " << d << ": " << ((c >= d) ? "true" : "false") << std::endl; // Expected true

		std::cout << b << " == " << c << ": " << ((b == c) ? "true" : "false") << std::endl; // Expected true
		std::cout << b << " != " << c << ": " << ((b != c) ? "true" : "false") << std::endl; // Expected false

		std::cout << c << " == " << d << ": " << ((c == d) ? "true" : "false") << std::endl; // Expected false
		std::cout << c << " != " << d << ": " << ((c != d) ? "true" : "false") << std::endl; // Expected true

		std::cout << c << " == " << e << ": " << ((c == e) ? "true" : "false") << std::endl; // Expected true
		std::cout << c << " != " << e << ": " << ((c != e) ? "true" : "false") << std::endl; // Expected false
	}
	{
		std::cout << "\nTest increment and decrement: " << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f).operator*(Fixed(2)));
		Fixed c = Fixed(25.45f);
		
		// Print the initial value of 'a'
		std::cout << "Initial value of a: " << a << std::endl;

		// Pre-increment 'a' (++a)
		std::cout << "Pre-increment ++a: " << ++a << std::endl;

		// Print the value of 'a' after pre-increment
		std::cout << "Value of a after pre-increment: " << a << std::endl;

		// Post-increment 'a' (a++)
		std::cout << "Post-increment a++: " << a++ << std::endl;

		// Print the value of 'a' after post-increment
		std::cout << "Value of a after post-increment: " << a << std::endl;

		// Print the value of 'b'
		std::cout << "Value of c: " << c << std::endl;

		// Pre-decrement 'c' (--c)
		std::cout << "Pre-decrement --c: " << --c << std::endl;

		// Post-decrement 'c' (c--)
		std::cout << "Post-decrement c--: " << c-- << std::endl;

		// Print the value of 'c' after post-decrement
		std::cout << "Value of c after post-decrement: " << c << std::endl;

		// Print the max value between 'a' and 'b'
		std::cout << "Max of a " << a.toFloat() << " and b " << b.toFloat() << " is " << Fixed::max(a, b) << std::endl;

		// Print the max value between 'a' and 'b'
		std::cout << "Min of a " << a.toFloat() << " and b " << b.toFloat() << " is " << Fixed::min(a, b) << std::endl;
	}
	{
	{		
		std::cout << "\nTest arithmetic operations: " << std::endl;
		Fixed fixed1(2);
		Fixed fixed2(3.5f);

		// Test arithmetic operations
		Fixed sum = fixed1 + fixed2;
		Fixed diff = fixed1 - fixed2;
		Fixed prod = fixed1 * fixed2;
		Fixed quot = fixed1 / fixed2;

		std::cout << fixed1.toFloat() << " + " << fixed2.toFloat() << " = " << sum << std::endl;
		std::cout << fixed1.toFloat() << " - " << fixed2.toFloat() << " = " << diff << std::endl;
		std::cout << fixed1.toFloat() << " * " << fixed2.toFloat() << " = " << prod << std::endl;
		std::cout << fixed1.toFloat() << " / " << fixed2.toFloat() << " = " << quot << std::endl;
	}
		Fixed a(2);           // Represents 2.0
		Fixed b(3.5f);       // Represents 3.5
		Fixed c(0.5f);       // Represents 0.5
		Fixed d(1);          // Represents 1.0
		Fixed e(-1.0f);      // Represents -1.0
		Fixed f(0);          // Represents 0.0

		std::cout << "a: " << a.toFloat() << "\nb: " << b.toFloat() 
		<< "\nc: " << c.toFloat() << "\nd: " << d.toFloat() <<
		"\ne: " << e.toFloat() << "\nf: " << f.toFloat() << std::endl;
		
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

		// Division by zero
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
		float input1;
		float input2;
		
		while (true)
		{
			if (std::cin.eof())
				break ;
			std::cout << "Input first (float or int) number: "; 
			std::cin >> input1;
			std::cout << "Input second (float or int) number: "; 
			std::cin >> input2;

			Fixed fixed1(input1);
			Fixed fixed2(input2);
			
			std::cout << "RUNNING TEST ON FIXED POINT VALUES: ";
			runTest(fixed1, fixed2);
		}
	}
	return 0;
}
