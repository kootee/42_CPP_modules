/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:45 by ktoivola          #+#    #+#             */
/*   Updated: 2025/01/28 20:28:04 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConverterFunctions.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

static int getLiteralType(const std::string &to_convert)
{
	if (to_convert.length() == 0)
		return INVALID;
    if (to_convert.length() == 1 && !std::isdigit(to_convert[0]))
        return CHAR;
		
	if (to_convert == "nanf" ||  
		to_convert == "+inff" ||
		to_convert == "-inff" )
		return FLOAT;
    
	if (to_convert == "nan" ||  
        to_convert == "+inf" ||
        to_convert == "-inf" )
        return DOUBLE;

    bool isInt = true;
    for (size_t i = 0; i < to_convert.length(); ++i)
    {
        if (i == 0 && (to_convert[i] == '-' || to_convert[i] == '+'))
            continue;
        if (!std::isdigit(to_convert[i]))
        {
            isInt = false;
            break;
        }
    }
    if (isInt)
        return INT;
    if (to_convert.back() == 'f' && 
		to_convert.find("inf") == std::string::npos && 
		to_convert.find("nan") == std::string::npos)
    {
        std::string s = to_convert.substr(0, to_convert.length() - 1);
        try
        {
            std::stof(s);
            return FLOAT;
			std::cout << "was float";
        }
        catch (const std::exception& e) 
		{
			return INVALID;
		}
    }
    if (to_convert.find('.') != std::string::npos)
    {
        try
        {
            std::stod(to_convert);
            return DOUBLE;
        }
        catch (const std::exception& e) 
		{
			return INVALID;
		}
    }
    return INVALID;
}

static void printConversionResult(ConversionResult result)
{
	std::cout << "char: ";
    if (result.charStatus == VALID)
		std::cout << "'" << result.charValue << "'\n";
	else if (result.charStatus == INVALID)   
		std::cout << "impossible\n";
	else
		std::cout << "Non displayable\n";

    std::cout << "int: ";
    if (result.intStatus == VALID)
        std::cout << result.intValue << "\n";
    else if (result.intStatus == INVALID)
		std::cout << "impossible\n";

    std::cout << "float: ";
    if (result.floatStatus == VALID)
        std::cout << std::fixed << std::setprecision(1) 
				<< result.floatValue << "f" << "\n";
    else
        std::cout << "impossible\n";

    std::cout << "double: ";
    if (result.doubleStatus == VALID)
        std::cout << std::fixed << std::setprecision(1) 
				<< result.doubleValue << "\n";
    else
        std::cout << "impossible\n";
}

void ScalarConverter::convert(const std::string &to_convert)
{
    ConversionResult result;

	switch(getLiteralType(to_convert))
	{
		case 0:
			result = ConverterFunctions::convertChar(to_convert);
			break;
		case 1:
			result = ConverterFunctions::convertInt(to_convert);
			break;
		case 2:
			result = ConverterFunctions::convertFloat(to_convert);
			break;
		case 3:
			result = ConverterFunctions::convertDouble(to_convert);
			break;
		default:
			std::cout << "Invalid literal\n";
			return;
	}
	printConversionResult(result);
}