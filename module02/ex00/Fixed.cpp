/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 13:42:11 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
const int Fixed::_bits = 8;

Fixed::Fixed () : _fixed_pt(0) { std::cout << DEFAULT_CONST << std::endl; };

Fixed::Fixed (const Fixed& copy) : _fixed_pt(copy._fixed_pt) 
{
    _fixed_pt = copy.getRawBits();
    std::cout << COPY_CONST << std::endl;
}

Fixed::~Fixed () { std::cout << DESTRUCTOR << std::endl; };

/* Operator overloads */
Fixed& Fixed::operator= (const Fixed& og_obj)
{
    if (this != &og_obj)
        _fixed_pt = og_obj.getRawBits();
    std::cout << COPY_ASSIGN << std::endl;
    return (*this);
}

/* Class member functions */
int     Fixed::getRawBits(void) const
{
    std::cout << "Get raw bits called" << std::endl;
    return (_fixed_pt);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "Set raw bits called" << std::endl;
    _fixed_pt = raw;
}