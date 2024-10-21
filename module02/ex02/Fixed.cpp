/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/21 11:19:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
const int Fixed::_bits = 8;

Fixed::Fixed () : _fixed_pt(0) 
{ 
    std::cout << DEFAULT_CONST << std::endl; 
}

Fixed::Fixed (const int int_value) 
{
    _fixed_pt = int_value << Fixed::_bits;
    std::cout << INT_CONST << std::endl;
}

Fixed::Fixed (const float float_value)
{
    _fixed_pt = roundf(float_value * (1 << Fixed::_bits));
    std::cout << FLOAT_CONST << std::endl;
}

Fixed::Fixed (const Fixed& copy) 
{
    _fixed_pt = copy.getRawBits();
    std::cout << COPY_CONST << std::endl;
}

Fixed::~Fixed () 
{
    std::cout << DESTRUCTOR << std::endl;
}

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
int     Fixed::getRawBits(void) const { return (_fixed_pt); }

void    Fixed::setRawBits(int const raw) { _fixed_pt = raw; }

float   Fixed::toFloat(void) const { return ((float)((float)((_fixed_pt) / (float)(1 << Fixed::_bits)))); }

int     Fixed::toInt(void) const { return (_fixed_pt >> Fixed::_bits); }

/* Comparison operator overloads */
bool    Fixed::operator<(const Fixed& comp_val) const
{
    return (this->_fixed_pt < comp_val._fixed_pt);
}

bool Fixed::operator>(const Fixed& comp_val) const
{
    return (this->_fixed_pt > comp_val._fixed_pt);
}

bool Fixed::operator<=(const Fixed& comp_val) const
{
    return (!(*this > comp_val));
}

bool Fixed::operator>=(const Fixed& comp_val) const
{
    return (!(*this < comp_val));
}

bool Fixed::operator==(const Fixed& comp_val) const
{
    return (this->_fixed_pt == comp_val._fixed_pt);
}

bool Fixed::operator!=(const Fixed& comp_val) const
{
    return (!(*this == comp_val));
}

/* Arithmetic operator overloads */
Fixed Fixed::operator+(const Fixed& add_val) const 
{
    Fixed   res;
    res.setRawBits((*this)._fixed_pt + add_val._fixed_pt);
    return (res);
}
Fixed Fixed::operator-(const Fixed& sub_val) const 
{
    Fixed res;
    res.setRawBits((*this)._fixed_pt - sub_val._fixed_pt);
    return (res);
}
Fixed Fixed::operator*(const Fixed& mult_val) const
{
    Fixed res;
    res.setRawBits(((*this)._fixed_pt * mult_val._fixed_pt) >> Fixed::_bits);
    return (res);
}
Fixed Fixed::operator/(const Fixed& div_val) const
{
    Fixed res;
    if (div_val._fixed_pt == 0)
        throw std::runtime_error("division by zero");
    res.setRawBits(((*this)._fixed_pt << _bits) / div_val._fixed_pt);
    return (res);
}

/* Increment/decrement operator overloads */
Fixed&	Fixed::operator++() // Pre-increment
{
    _fixed_pt += 1;
    return (*this);
}

Fixed&	Fixed::operator--() // Pre-decrement
{
    _fixed_pt -= 1;
    return (*this);
}

Fixed	Fixed::operator++(int) // Post-increment
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed	Fixed::operator--(int) // Post-decrement
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}

/* Min max overload member functions */
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits()) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits()) ? fixed1 : fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits()) ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits()) ? fixed1 : fixed2;
}