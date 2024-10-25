/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/24 10:45:03 by ktoivola         ###   ########.fr       */
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
    std::cout << INT_CONST << std::endl;
    _fixed_pt = int_value << Fixed::_bits;
}

Fixed::Fixed (const float float_value)
{
    std::cout << FLOAT_CONST << std::endl;
    _fixed_pt = roundf(float_value * (1 << Fixed::_bits));
}

Fixed::Fixed (const Fixed& to_copy) 
{
    std::cout << COPY_CONST << std::endl;
    _fixed_pt = to_copy.getRawBits();
}

Fixed::~Fixed () 
{
    std::cout << DESTRUCTOR << std::endl;
}

/* Operator overloads */
Fixed& Fixed::operator= (const Fixed& to_copy)
{
    std::cout << COPY_ASSIGN << std::endl;
    if (this != &to_copy)
        _fixed_pt = to_copy.getRawBits();
    return (*this);
}

std::ostream& operator<< (std::ostream &other, const Fixed &fixed_pt)
{
    other << fixed_pt.toFloat();
    return (other);
}

/* Class member functions */
int     Fixed::getRawBits(void) const { return (_fixed_pt); }

void    Fixed::setRawBits(int const raw) { _fixed_pt = raw; }

float   Fixed::toFloat(void) const { return (_fixed_pt / (float)(1 << Fixed::_bits)); }

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
    return (this->toFloat() + add_val.toFloat());
}
Fixed Fixed::operator-(const Fixed& sub_val) const 
{
    return ((*this).toFloat() - sub_val.toFloat());
}

Fixed Fixed::operator*(const Fixed& mult_val) const
{
    return (this->toFloat() * mult_val.toFloat());
}
Fixed Fixed::operator/(const Fixed& div_val) const
{
    if (div_val._fixed_pt == 0)
        throw std::runtime_error("division by zero");
    return (this->toFloat() / div_val.toFloat());
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