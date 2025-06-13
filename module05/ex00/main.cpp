/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:19:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 16:03:59 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {

    try {
        // Test with a valid grade
        std::cout << "-----Testing a valid bureaucrat-----" << "\n";
        Bureaucrat validBureaucrat("John Doe", 100);
        std::cout << "Printing bureaucrat information:" << "\n";
        std::cout << validBureaucrat << "\n";

        // Test incrementing the grade
        validBureaucrat.incrementGrade();
        std::cout << "After incrementing: \n" << validBureaucrat << "\n";

        // Test decrementing the grade
        validBureaucrat.decrementGrade();
        std::cout << "After decrementing: \n" << validBureaucrat << "\n";

        std::cout << "-----Creating some copies-----" << "\n";
        Bureaucrat copy1("Big Boss", 25);
        copy1 = validBureaucrat;
        Bureaucrat copy2(copy1);

        std::cout << "1st copy " << copy1;
        std::cout << "2nd copy " << copy2;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n-----Testing some invalid bureaucrats-----" << "\n";
    // Test with an invalid low grade (below 1)
    try 
    {
        Bureaucrat tooHigh("Top Bureaucrat", 0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    
    // Test with an invalid high grade (above 150)
    try {
        Bureaucrat tooLow("Lowly Bureaucrat", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Bureaucrat crazy("Crazy Bureaucrat", -15122222);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    
    std::cout << "\n-----Testing some more bureaucrats-----" << "\n";
    // Test incrementing the grade to exceed the limit
    try {
        Bureaucrat nearTop("Hotshot", 2);
        std::cout << "Printing bureaucrat information:" << "\n";
        std::cout << nearTop << "\n";
        nearTop.incrementGrade(); // Should be fine
        std::cout << "After increment: " << nearTop << "\n";
        std::cout << "Trying to increment too much\n";
        nearTop.incrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n-----Testing decrementing-----" << "\n";
    // Test decrementing the grade to exceed the limit
    try {
        Bureaucrat nearBottom("Sloth", 149);
        std::cout << "Printing bureaucrat information:" << "\n";
        std::cout << nearBottom << "\n";
        nearBottom.decrementGrade(); // Should be fine
        std::cout << "After decrement: \n" << nearBottom << "\n";
        nearBottom.decrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}
