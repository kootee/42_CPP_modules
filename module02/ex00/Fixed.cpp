/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 09:44:49 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
const int Fixed::_bits = 8;

Fixed::Fixed () : _fixed_pt(0) { std::cout << DEFAULT_CONST << std::endl; };

Fixed::Fixed (const Fixed& copy) : _fixed_pt(copy._fixed_pt) 
{
    std::cout << COPY_CONST << std::endl;
    _fixed_pt = copy.getRawBits();
}

Fixed::~Fixed () { std::cout << DESTRUCTOR << std::endl; };

/* Operator overloads */
Fixed& Fixed::operator= (const Fixed& og_obj)
{
    std::cout << COPY_ASSIGN << std::endl;
    if (this != &og_obj)
        _fixed_pt = og_obj.getRawBits();
    return (*this);
}

/* Class member functions */
int     Fixed::getRawBits(void) const
{
    std::cout << GET_RAW_BITS << std::endl;
    return (_fixed_pt);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << SET_RAW_BITS << std::endl;
    _fixed_pt = raw;
}