/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 10:52:02 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed:: _bits = 8;

Fixed::Fixed () : _fixed_pt(0) {std::cout << "Default constructor called" << std::endl;};

Fixed::Fixed (const int int_value) : _fixed_pt(int_value) 
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float float_value) : _fixed_pt(float_value) 
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& copy) : _fixed_pt(copy._fixed_pt) {std::cout << "Copy constructor called" << std::endl;};

Fixed::~Fixed () {std::cout << "Destructor called" << std::endl;};

Fixed& Fixed::operator= (const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fixed_pt = fixed._fixed_pt;
    return *this;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "Get raw bits called" << std::endl;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "Set raw bits called" << std::endl;
}