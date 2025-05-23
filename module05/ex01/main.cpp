/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:19:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 16:39:41 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "-----Testing form creation-----" << std::endl;
    try {
        // Test creating a valid form
        try {
            Form validForm("Standard Form", 50, 75);
            std::cout << "Created a valid form successfully:\n" 
            << validForm;

            Form copy1 = validForm;
            Form copy2(copy1);

            std::cout << "Created two copied forms: \ncopy1: " << copy1 << "copy2: " << copy2;

        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test creating a form with an invalid sign grade (too high)
        try {
            std::cout << "\n-----Testing invalid form-----" << std::endl;
            Form invalidSignHigh("Invalid Form High Sign", 0, 75);
        } catch (const std::exception& e) {
            std::cerr << "Caught an exception for high sign grade: " << e.what() << std::endl;
        }

        // Test creating a form with an invalid execute grade (too low)
        try {
            std::cout << "\n-----Testing invalid form-----" << std::endl;
            Form invalidExecLow("Invalid Form Low Exec", 50, 200);
        } catch (const std::exception& e) {
            std::cerr << "Caught an exception for low execute grade: " << e.what() << std::endl;
        }

        std::cout << "\n-----Testing form signing-----" << std::endl;

        // Test bureaucrat signing a form they are qualified for
        try {
            Bureaucrat capableBureaucrat("Alice", 30);
            Form importantForm("Important Form", 50, 45);

            std::cout << "Bureaucrat stats: \n" << capableBureaucrat;
            std::cout << "Before signing:\n" << importantForm;
            capableBureaucrat.signForm(importantForm);
            std::cout << "After signing:\n" << importantForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test bureaucrat trying to sign a form they are not qualified for
        try {
            std::cout << "\n-----Testing unqualified bureaucrat trying to sign form-----" << std::endl;
            Bureaucrat juniorBureaucrat("Bob", 120);
            Form complexForm("Complex Form", 50, 60);

            std::cout << "Bureaucrat stats: \n" << juniorBureaucrat;
            std::cout << "Before signing:\n" << complexForm;
            juniorBureaucrat.signForm(complexForm);  // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test with a bureaucrat at the exact threshold of signing capability
        try {
            std::cout << "\n-----Testing barely qualified bureaucrat trying to sign form-----" << std::endl;
            Bureaucrat exactThreshold("Charlie", 50);
            Form exactForm("Exact Form", 50, 50);

            std::cout << "Bureaucrat stats: \n" << exactThreshold;
            std::cout << "Before signing:\n" << exactForm;
            exactThreshold.signForm(exactForm);
            std::cout << "After signing:\n" << exactForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test creating a form and attempting to sign with a grade that's highest possible
        try {
            std::cout << "\n-----Testing elite bureaucrat trying to sign ultra secure form-----" << std::endl;

            Bureaucrat topBureaucrat("Elite", 1);
            Form ultraForm("Ultra Secure Form", 1, 1);

            std::cout << "Bureaucrat stats: \n" << topBureaucrat;
            std::cout << "Before signing:\n" << ultraForm;
            topBureaucrat.signForm(ultraForm);  // Should succeed
            std::cout << "After signing:\n" << ultraForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test creating a form and attempting to sign with a grade that's lowest possible
        try {
            std::cout << "\n-----Testing lazy bureaucrat trying to sign super easy form-----" << std::endl;

            Bureaucrat lazyBureaucrat("Lazy", 150);
            Form easyForm("Ultra lazy Form", 150, 1);

            std::cout << "Bureaucrat stats: \n" << lazyBureaucrat;
            std::cout << "Before signing:\n" << easyForm;
            lazyBureaucrat.signForm(easyForm);  // Should succeed
            std::cout << "After signing:\n" << easyForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
