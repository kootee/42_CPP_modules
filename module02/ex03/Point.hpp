/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:31:21 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/22 13:06:46 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
			const Fixed	x;
			const Fixed	y;
	public:
			Point();							// Default constructor
			Point(const float, const float);	// Float constructor
            Point(const Point&);				// Copy constructor
            ~Point();							// Destructor
            
			Point&	operator=(const Point&);    // Copy assignment operator overload
            
            float   getX() const;
            float   getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif