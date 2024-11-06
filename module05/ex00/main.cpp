/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:19:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 08:31:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        // Test with a valid grade
        std::cout << "-----Testing a valid bureaucrat-----" << std::endl;
        Bureaucrat validBureaucrat("John Doe", 100);
        std::cout << "Printing bureaucrat information:" << std::endl;
        std::cout << validBureaucrat << std::endl;

        // Test incrementing the grade
        validBureaucrat.incrementGrade();
        std::cout << "After incrementing: \n" << validBureaucrat << std::endl;

        // Test decrementing the grade
        validBureaucrat.decrementGrade();
        std::cout << "After decrementing: \n" << validBureaucrat << std::endl;

        std::cout << "-----Testing some invalid bureaucrats-----" << std::endl;
        // Test with an invalid low grade (below 1)
        try 
        {
            Bureaucrat tooHigh("Top Bureaucrat", 0);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test with an invalid high grade (above 150)
        try {
            Bureaucrat tooLow("Lowly Bureaucrat", 151);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
        std::cout << "-----Testing some more bureaucrats-----" << std::endl;
        // Test incrementing the grade to exceed the limit
        try {
            Bureaucrat nearTop("Hotshot", 2);
            std::cout << "Printing bureaucrat information:" << std::endl;
            std::cout << nearTop << std::endl;
            nearTop.incrementGrade(); // Should be fine
            std::cout << "After increment: \n" << nearTop << std::endl;
            nearTop.incrementGrade(); // Should throw
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test decrementing the grade to exceed the limit
        try {
            Bureaucrat nearBottom("Sloth", 149);
            std::cout << "Printing bureaucrat information:" << std::endl;
            std::cout << nearBottom << std::endl;
            nearBottom.decrementGrade(); // Should be fine
            std::cout << "After decrement: \n" << nearBottom << std::endl;
            nearBottom.decrementGrade(); // Should throw
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
