/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/22 17:47:04 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "BSP TESTS WITH TRIANGLE (0,0) | (5,0) | (0,5)" << std::endl;

        // Test case 1: Point inside the triangle
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        
        Point pointInside(1.0f, 1.0f);
        std::cout << "Test Case 1 (Inside): " << (bsp(a, b, c, pointInside)  ? "true" : "false") 
        << " (Expected: true)" << std::endl;

        // Test case 2: Point outside the triangle
        Point pointOutside(6.0f, 1.0f);
        std::cout << "Test Case 2 (Outside): " << (bsp(a, b, c, pointOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        // Test case 3: Point on an edge of the triangle
        Point pointOnEdge(0.0f, 2.0f);
        std::cout << "Test Case 3 (On Edge): " << (bsp(a, b, c, pointOnEdge)  ? "true" : "false")
        << " (Expected: false)" << std::endl;

        // Test case 4: Point at the vertex of the triangle
        Point pointAtVertex(5.0f, 0.0f);
        std::cout << "Test Case 4 (At Vertex): " << (bsp(a, b, c, pointAtVertex)   ? "true" : "false")
        << " (Expected: false)" << std::endl;

        // Test case 5: Point far outside the triangle
        Point farOutside(10.0f, 10.0f);
        std::cout << "Test Case 5 (Far Outside): " << (bsp(a, b, c, farOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        // On edge
        Point pointRoundsToEdge(2.499f, 2.499f);
        std::cout << "Test Case 6 (Rounds to edge): " << (bsp(a, b, c, pointRoundsToEdge)   ? "true" : "false")
        << " (Expected: false)" << std::endl;

        // Barely Inside 
        Point pointRoundsToInside(2.49f, 2.49f);
        std::cout << "Test Case 7 (Rounds to just inside): " << (bsp(a, b, c, pointRoundsToInside)   ? "true" : "false")
        << " (Expected: true)" << std::endl;

        // Point on the edge with floating-point precision
        Point pointOnEdgePrecise(2.5f, 2.5f);
        std::cout << "Test Case 8 (On Edge with Precision): " << (bsp(a, b, c, pointOnEdgePrecise)   ? "true" : "false")
        << " (Expected: false)" << std::endl;

        // Point very close to the triangle but outside
        Point pointVeryCloseOutside(5.0001f, -0.0001f);
        std::cout << "Test Case 9 (Very Close Outside): " << (bsp(a, b, c, pointVeryCloseOutside)  ? "true" : "false") 
        << " (Expected: false)" << std::endl;

        // Point slightly inside the triangle
        Point pointSlightlyInside(0.9999f, 0.999f);
        std::cout << "Test Case 10 (Slightly Inside): " << (bsp(a, b, c, pointSlightlyInside)   ? "true" : "false")
        << " (Expected: true)" << std::endl;

        Point pointLargeNeg(-5452.5f, 692.5f);
        std::cout << "Test Case 11 (Point far away): " 
        << (bsp(Point(-1.5f, 1.5f), Point(-6.0f, 1.5f), Point(1.5f, -60.0f), pointLargeNeg)   ? "true" : "false")
        << " (Expected: false)" << std::endl;
    }

    return 0;
}
