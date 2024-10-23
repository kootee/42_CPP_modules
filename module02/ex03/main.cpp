/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 09:41:45 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    {
        std::cout << "BSP TESTS WITH TRIANGLE (0,0) | (5,0) | (0,5)" << std::endl;

        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        
        Point pointInside(1.0f, 1.0f);
        std::cout << "Test Case 1 (Inside): " << (bsp(a, b, c, pointInside)  ? "true" : "false") 
        << " (Expected: true)" << std::endl;

        Point pointOutside(6.0f, 1.0f);
        std::cout << "Test Case 2 (Outside): " << (bsp(a, b, c, pointOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        Point pointOnEdge(0.0f, 2.0f);
        std::cout << "Test Case 3 (On Edge): " << (bsp(a, b, c, pointOnEdge)  ? "true" : "false")
        << " (Expected: false)" << std::endl;

        Point pointAtVertex(5.0f, 0.0f);
        std::cout << "Test Case 4 (At Vertex): " << (bsp(a, b, c, pointAtVertex)   ? "true" : "false")
        << " (Expected: false)" << std::endl;
        
        Point farOutside(10.0f, 10.0f);
        std::cout << "Test Case 5 (Far Outside): " << (bsp(a, b, c, farOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        Point pointRoundsToEdge(2.499f, 2.499f);
        std::cout << "Test Case 6 (Rounds to edge): " << (bsp(a, b, c, pointRoundsToEdge)   ? "true" : "false")
        << " (Expected: false)" << std::endl;

        Point pointRoundsToInside(2.49f, 2.49f);
        std::cout << "Test Case 7 (Rounds to just inside): " << (bsp(a, b, c, pointRoundsToInside)   ? "true" : "false")
        << " (Expected: true)" << std::endl;

        Point pointOnEdgePrecise(2.5f, 2.5f);
        std::cout << "Test Case 8 (On Edge with Precision): " << (bsp(a, b, c, pointOnEdgePrecise)   ? "true" : "false")
        << " (Expected: false)" << std::endl;

        Point pointVeryCloseOutside(5.0001f, -0.0001f);
        std::cout << "Test Case 9 (Very Close Outside): " << (bsp(a, b, c, pointVeryCloseOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        Point pointSlightlyInside(0.9999f, 0.999f);
        std::cout << "Test Case 10 (Inside): " << (bsp(a, b, c, pointSlightlyInside)   ? "true" : "false")
        << " (Expected: true)" << std::endl;

        Point pointLargeNeg(-5452.5f, 692.5f);
        std::cout << "Test Case 11 (Point far away): " 
        << (bsp(Point(-1.5f, 1.5f), Point(-6.0f, 1.5f), Point(1.5f, -60.0f), pointLargeNeg)   ? "true" : "false")
        << " (Expected: false)" << std::endl;
    }

    return 0;
}
