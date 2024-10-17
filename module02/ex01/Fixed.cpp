/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/17 11:37:25 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed () : _fixed_pt(0) { std::cout << DEFAULT_CONST << std::endl; }

Fixed::Fixed (const int int_value) 
{
    _fixed_pt = int_value << _bits;
    std::cout << INT_CONST << std::endl;
}

Fixed::Fixed (const float float_value)
{
    _fixed_pt = roundf(float_value * (1 << _bits));
    std::cout << FLOAT_CONST << std::endl;
}

Fixed::Fixed (const Fixed& copy) 
{
    _fixed_pt = copy.getRawBits();
    std::cout << COPY_CONST << std::endl;
}

Fixed::~Fixed () {std::cout << DESTRUCTOR << std::endl;};

/* Operator overloads */
Fixed& Fixed::operator= (const Fixed& og_obj)
{
    if (this != &og_obj)
        _fixed_pt = og_obj.getRawBits();
    std::cout << COPY_ASSIGN << std::endl;
    return (*this);
}

std::ostream& operator<< (std::ostream &os_obj, const Fixed &fixed_pt)
{
    os_obj << fixed_pt.toFloat();
    return (os_obj);
}

/* Class member functions */
int     Fixed::getRawBits(void) const
{
    std::cout << GET_RAW_BITS << std::endl;
    return (_fixed_pt);
}

void    Fixed::setRawBits(int const raw)
{
    _fixed_pt = raw;
    std::cout << SET_RAW_BITS << std::endl;
}

float   Fixed::toFloat(void) const { return ((float)((_fixed_pt) / (1 << _bits))); }

int     Fixed::toInt(void) const { return (_fixed_pt >> _bits); }