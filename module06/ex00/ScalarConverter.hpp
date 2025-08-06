/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:47 by ktoivola          #+#    #+#             */
/*   Updated: 2025/01/28 15:35:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter() = default;
        ScalarConverter(const ScalarConverter &) = default;
        virtual ~ScalarConverter() = 0;

        ScalarConverter& operator=(const ScalarConverter&) = default;
        
    public:
        static void convert(const std::string &);
};

