/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 19:05:11 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ~ScalarConverter();

    static void convertChar(const std::string &);
    static void convertInt(const std::string &);
    static void convertFloat(const std::string &);
    static void convertDouble(const std::string &);
public:
    static void convert(std::string);
};

