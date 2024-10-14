/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:53:03 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 10:21:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed:: _bits = 8;

Fixed::Fixed () : _fixed_pt(0) {};

Fixed::Fixed (const Fixed& copy) : _fixed_pt(copy._fixed_pt) {};

Fixed& Fixed::operator= (const Fixed& fixed)
{
    _fixed_pt = fixed._fixed_pt;
    return *this;
}