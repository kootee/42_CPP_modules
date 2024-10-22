/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:22:08 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/22 17:29:16 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float s1;
    float s2;
    float s3;

    s1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) 
        - (point.getY() - a.getY()) * (b.getX() - a.getX());
    s2 = (point.getX() - b.getX()) * (c.getY() - b.getY()) 
        - (point.getY() - b.getY()) * (c.getX() - b.getX());
    s3 = (point.getX() - c.getX()) * (a.getY() - c.getY()) 
        - (point.getY() - c.getY()) * (a.getX() - c.getX());

    bool neg_sign = false;
    bool pos_sign = false;
    
    if (s1 < 0 || s2 < 0 || s3 < 0)
        neg_sign = true;
    if (s1 >= 0 || s2 >= 0 || s3 >= 0)
        pos_sign = true;
    return (neg_sign != pos_sign); 
}