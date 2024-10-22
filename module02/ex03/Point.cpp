/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:28:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/22 11:32:56 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point () : x(0), y(0) {}

Point::Point (const float val1, const float val2) : x(val1), y(val2) {}

Point::Point (const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator= (const Point& other) { (void)other; return (*this); }

Point::~Point() {}

float   Point::getX() const { return (x.toFloat()); }

float   Point::getY() const { return (y.toFloat()); }