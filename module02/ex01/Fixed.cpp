/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:25 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */

const int Fixed:: _bits = 8;

Fixed::Fixed () : _fixed_pt(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int int_value) : _fixed_pt(int_value) 
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float float_value) : _fixed_pt(float_value) 
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& copy) : _fixed_pt(copy._fixed_pt) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed () {std::cout << "Destructor called" << std::endl;};

/* Operator overloads */
Fixed& Fixed::operator= (const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fixed_pt = fixed._fixed_pt;
    return *this;
}

Fixed& Fixed::operator<< (std::ostream &os_obj)
{

}

/* Class functions */
float   Fixed::toFloat(void) const
{
    
}

int     Fixed::toInt(void) const
{
    
}

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