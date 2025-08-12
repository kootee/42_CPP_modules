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
#include <limits>

int main(int argc, char** argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
        std::cout << "---RUNNING TESTS---\n";
        std::cout << "\nTESTING CHAR LITERALS\n";
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

        std::cout << "\nTesting:  \n";
        ScalarConverter::convert(" "); // Space

        std::cout << "\nTesting: -\n";
        ScalarConverter::convert("-"); // Just a minus sign

        std::cout << "\nTesting: +\n";
        ScalarConverter::convert("+"); // Just a plus sign

        std::cout << "\nTesting: .\n";
        ScalarConverter::convert("."); // Just a dot

        std::cout << "\nTesting: f\n";
        ScalarConverter::convert("f"); // Just an 'f'

        std::cout << "\nTESTING INT LITERALS\n";
        std::cout << "\nTesting: 42\n";
        ScalarConverter::convert("42");

        std::cout << "\nTesting: -42\n";
        ScalarConverter::convert("-42");

        std::cout << "\nTesting: 0\n";
        ScalarConverter::convert("0"); // Zero as int

        std::cout << "\nTesting: -0\n";
        ScalarConverter::convert("-0"); // Negative zero

        int intMin = std::numeric_limits<int>::lowest();
        int intMax = std::numeric_limits<int>::max();
        std::string minIntStr = std::to_string(intMin);
        std::string maxIntStr = std::to_string(intMax);

        std::cout << "\nTesting: " << minIntStr << "\n";
        ScalarConverter::convert(minIntStr);

        std::cout << "\nTesting: " << maxIntStr << "\n";
        ScalarConverter::convert(maxIntStr);

        std::cout << "\nTESTING FLOAT LITERALS\n";
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

        float minFloat = std::numeric_limits<float>::lowest();
        float maxFloat = std::numeric_limits<float>::max();
        std::string minFloatStr = std::to_string(minFloat);
        std::string maxFloatStr = std::to_string(maxFloat);
        
        std::cout << "\nTesting: " << minFloatStr << "\n";
        ScalarConverter::convert(minFloatStr);

        std::cout << "\nTesting: " << maxFloatStr << "\n";
        ScalarConverter::convert(maxFloatStr);

        std::cout << "\nTESTING DOUBLE LITERALS\n";
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

        double minDouble = std::numeric_limits<double>::lowest();
        double maxDouble = std::numeric_limits<double>::max();
        std::string minDoubleStr = std::to_string(minDouble);
        std::string maxDoubleStr = std::to_string(maxDouble);

        std::cout << "Testing: " << minDoubleStr << "\n";
        ScalarConverter::convert(minDoubleStr);

        std::cout << "Testing: " << maxDoubleStr << "\n";
        ScalarConverter::convert(maxDoubleStr);

        std::cout << "\nTESTING RANDOM LITERALS\n";
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

        std::cout << "\nTesting: nanff\n";
        ScalarConverter::convert("nanff"); // Invalid pseudo-literal

        std::cout << "\nTesting: inff\n";
        ScalarConverter::convert("inff"); // Missing '+' or '-' for infinity
    }
}
