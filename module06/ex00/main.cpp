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

int main()
{
    // Test cases
    std::cout << "Testing ScalarConverter::convert()" << std::endl;

    // Char literals
    ScalarConverter::convert("a");
    ScalarConverter::convert("z");
    ScalarConverter::convert("!");

    // Int literals
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("2147483647"); // INT_MAX
    ScalarConverter::convert("-2147483648"); // INT_MIN

    // Float literals
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.0f");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    // Double literals
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("-42.0");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");

    // Invalid inputs
    ScalarConverter::convert("abc");
    ScalarConverter::convert("42abc");
    ScalarConverter::convert("");

    return 0;
}
