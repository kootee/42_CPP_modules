/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:45 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/26 16:44:03 by ktoivola         ###   ########.fr       */
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
	
	long double	conversion;
	int			i = 0;

	for (i; i < to_convert.size(); i++)
	{
		if (std::isalpha(to_convert[i]))
		{
			break;
		}
	}
	if (i == to_convert.size())
		conversion = std::stold(to_convert, 0);
	else
		std::cout << "Incorrect value\n";

	charValue = conversion;
	intValue = conversion;
	floatValue = conversion;
	doubleValue = conversion;
	
	std::cout << "char:	" << charValue <<
				"\nint:	" << intValue <<
				"\nfloat:	" << floatValue <<
				"\ndouble:	" << doubleValue << std::endl;
}