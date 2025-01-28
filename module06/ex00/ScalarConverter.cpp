/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:45 by ktoivola          #+#    #+#             */
/*   Updated: 2025/01/28 17:35:02 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>

// Implicit scalar converter
void ScalarConverter::convert(const std::string &to_convert)
{
	char		charValue;
	int			intValue;
	float		floatValue; 
	double		doubleValue;
	long double	conversion;

	const char *str = to_convert.c_str();
	try
	{
		charValue = static_cast<char>(conversion);
		intValue = static_cast<int>(conversion);
		floatValue = static_cast<float>(conversion);
		doubleValue = static_cast<double>(conversion);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "char:	" << charValue <<
				"\nint:	" << intValue <<
				"\nfloat:	" << floatValue <<
				"\ndouble:	" << doubleValue << std::endl;
}