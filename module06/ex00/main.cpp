/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:25:09 by ktoivola          #+#    #+#             */
/*   Updated: 2025/01/28 15:36:42 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
        // Char literals
        std::cout << "---RUNNING TESTS---\n";
        std::cout << "Testing: a\n";
        ScalarConverter::convert("a");

        std::cout << "\nTesting: z\n";
        ScalarConverter::convert("z");

        std::cout << "\nTesting: !\n";
        ScalarConverter::convert("!");

        std::cout << "\nTesting: 1\n";
        ScalarConverter::convert("1"); // Single digit as char

        std::cout << "\nTesting: \\n\n";
        ScalarConverter::convert("\n"); // Non-printable char

        // Int literals
        std::cout << "\nTesting: 42\n";
        ScalarConverter::convert("42");

        std::cout << "\nTesting: -42\n";
        ScalarConverter::convert("-42");

        std::cout << "\nTesting: 2147483647\n";
        ScalarConverter::convert("2147483647"); // INT_MAX

        std::cout << "\nTesting: -2147483648\n";
        ScalarConverter::convert("-2147483648"); // INT_MIN

        std::cout << "\nTesting: 0\n";
        ScalarConverter::convert("0"); // Zero as int

        std::cout << "\nTesting: -0\n";
        ScalarConverter::convert("-0"); // Negative zero

        // Float literals
        std::cout << "\nTesting: 42.0f\n";
        ScalarConverter::convert("42.0f");

        std::cout << "\nTesting: -42.0f\n";
        ScalarConverter::convert("-42.0f");
        
		std::cout << "\nTesting: 235.565f\n";
        ScalarConverter::convert("235.565f");

        std::cout << "\nTesting: nanf\n";
        ScalarConverter::convert("nanf");

        std::cout << "\nTesting: +inff\n";
        ScalarConverter::convert("+inff");

        std::cout << "\nTesting: -inff\n";
        ScalarConverter::convert("-inff");

        std::cout << "\nTesting: 0.0f\n";
        ScalarConverter::convert("0.0f"); // Zero as float

        std::cout << "\nTesting: -0.0f\n";
        ScalarConverter::convert("-0.0f"); // Negative zero as float

        std::cout << "\nTesting: 1e-38f\n";
        ScalarConverter::convert("1e-38f"); // Smallest normalized float

        std::cout << "\nTesting: 1e+38f\n";
        ScalarConverter::convert("1e+38f"); // Largest normalized float

        std::cout << "\nTesting: 1.17549e-38f\n";
        ScalarConverter::convert("1.17549e-38f"); // Float min

        std::cout << "\nTesting: 3.40282e+38f\n";
        ScalarConverter::convert("3.40282e+38f"); // Float max

        // Double literals
        std::cout << "\nTesting: 42.0\n";
        ScalarConverter::convert("42.0");

        std::cout << "\nTesting: -42.0\n";
        ScalarConverter::convert("-42.0");
        
		std::cout << "\nTesting: 0.12335\n";
        ScalarConverter::convert("0.12335");

        std::cout << "\nTesting: -0.12335\n";
        ScalarConverter::convert("-0.12335");

        std::cout << "\nTesting: nan\n";
        ScalarConverter::convert("nan");

        std::cout << "\nTesting: +inf\n";
        ScalarConverter::convert("+inf");

        std::cout << "\nTesting: -inf\n";
        ScalarConverter::convert("-inf");

        std::cout << "\nTesting: 0.0\n";
        ScalarConverter::convert("0.0"); // Zero as double

        std::cout << "\nTesting: -0.0\n";
        ScalarConverter::convert("-0.0"); // Negative zero as double

        std::cout << "\nTesting: 2.22507e-308\n";
        ScalarConverter::convert("2.22507e-308"); // Double min

        std::cout << "\nTesting: 1.79769e+308\n";
        ScalarConverter::convert("1.79769e+308"); // Double max

        // Random inputs
        std::cout << "\nTesting: abc\n";
        ScalarConverter::convert("abc");

        std::cout << "\nTesting: 42abc\n";
        ScalarConverter::convert("42abc");

        std::cout << "\nTesting: fewgh5wegeer325--.,bre\n";
        ScalarConverter::convert("fewgh5wegeer325--.,bre");

        std::cout << "\nTesting: .fheow\n";
        ScalarConverter::convert(".fheow");

        std::cout << "\nTesting: .f\n";
        ScalarConverter::convert(".f");

        std::cout << "\nTesting: 00ir023\n";
        ScalarConverter::convert("00ir023");

        std::cout << "\nTesting: 00000.3t\n";
        ScalarConverter::convert("00000.3t");

        std::cout << "\nTesting: \n";
        ScalarConverter::convert(""); // Empty string

        std::cout << "\nTesting:  \n";
        ScalarConverter::convert(" "); // Space

        std::cout << "\nTesting: ..\n";
        ScalarConverter::convert(".."); // Multiple dots

        std::cout << "\nTesting: 42..0\n";
        ScalarConverter::convert("42..0");

        std::cout << "\nTesting: 42.0.0\n";
        ScalarConverter::convert("42.0.0");

        std::cout << "\nTesting: 42f\n";
        ScalarConverter::convert("42f");

        std::cout << "\nTesting: 42.0ff\n";
        ScalarConverter::convert("42.0ff"); // Extra 'f' in float

        std::cout << "\nTesting: -\n";
        ScalarConverter::convert("-"); // Just a minus sign

        std::cout << "\nTesting: +\n";
        ScalarConverter::convert("+"); // Just a plus sign

        std::cout << "\nTesting: .\n";
        ScalarConverter::convert("."); // Just a dot

        std::cout << "\nTesting: f\n";
        ScalarConverter::convert("f"); // Just an 'f'

        std::cout << "\nTesting: nanff\n";
        ScalarConverter::convert("nanff"); // Invalid pseudo-literal

        std::cout << "\nTesting: inff\n";
        ScalarConverter::convert("inff"); // Missing '+' or '-' for infinity
    }
}
