/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:45 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/26 16:19:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Implicit scalar converter
void ScalarConverter::convert(const std::string &to_convert)
{
	char	charValue;
	int		intValue;
	float	floatValue; 
	double	doubleValue; 
	
	if (to_convert.size() > 1)
	{
		std::cout << "incorrect argument\n";
		return;
	}

	charValue = to_convert[0];
	intValue = to_convert[0];
	floatValue = to_convert[0];
	doubleValue = to_convert[0];
	
	std::cout << "char: " << charValue <<
				"\nint: " << intValue <<
				"\nfloat: " << floatValue <<
				"\ndouble: " << doubleValue << std::endl;
}