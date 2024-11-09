/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:19:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 14:30:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main() {
    try {
        // Test with a valid bureaucrat
        std::cout << "-----Testing a valid bureaucrat-----" << std::endl;
        Bureaucrat validBureaucrat("John Doe", 100);
        Bureaucrat superBureaucrat("Robocop", 20);
        Bureaucrat semisuperBureaucrat("Robocop2", 45);
        std::cout << "Printing bureaucrat information:" << std::endl;
        std::cout << validBureaucrat;
        std::cout << superBureaucrat;
        std::cout << semisuperBureaucrat;

        // Test bureaucrat signing and executing forms

        std::cout << "\n-----Testing ShrubberyCreationForm-----" << std::endl;
        try {
            ShrubberyCreationForm shrubberyForm("Shrubbery Form");
            std::cout << "Form information:\n" << shrubberyForm;

            // Bureaucrat signing the form
            validBureaucrat.signForm(shrubberyForm);
            std::cout << "Form information:\n" << shrubberyForm;

            // Bureaucrat attempting to execute the form
            validBureaucrat.executeForm(shrubberyForm);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n-----Testing PresidentialPardonForm-----" << std::endl;
        try {
            PresidentialPardonForm presidentialForm("Presidential Pardon");
            std::cout << "Form information:\n" << presidentialForm;

            // Bureaucrat signing the form
            validBureaucrat.signForm(presidentialForm);
            std::cout << "Form information:\n" << presidentialForm;

            // Bureaucrat attempting to execute the form
            validBureaucrat.executeForm(presidentialForm);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n-----Testing RobotomyRequestForm-----" << std::endl;
        try {
            RobotomyRequestForm robotomyForm("Robotomy Request");
            std::cout << "Form information:\n" << robotomyForm;

            // Bureaucrat signing the form
            validBureaucrat.signForm(robotomyForm);
            std::cout << "Form information:\n" << robotomyForm;

            // Bureaucrat attempting to execute the form
            superBureaucrat.executeForm(robotomyForm);
            
            // Bureaucrat attempting to execute the form
            superBureaucrat.executeForm(robotomyForm);
            
            // Bureaucrat attempting to execute the form
            semisuperBureaucrat.executeForm(robotomyForm);
            
            // Bureaucrat attempting to execute the form
            semisuperBureaucrat.executeForm(robotomyForm);
        
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Testing bureaucrats with different grades trying to sign and execute forms
        std::cout << "\n-----Testing bureaucrat with insufficient grade-----" << std::endl;
        try {
            Bureaucrat juniorBureaucrat("Junior", 120);  // Not qualified to sign or execute

            ShrubberyCreationForm shrubberyForm("Shrubbery Form");
            std::cout << "\nBureaucrat information:\n" << juniorBureaucrat;

            std::cout << "Form information:\n" << shrubberyForm;
            juniorBureaucrat.signForm(shrubberyForm);  // Should throw exception
            juniorBureaucrat.executeForm(shrubberyForm);  // Should throw exception
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Bureaucrat with exact sign and execute capability
        std::cout << "\n-----Testing bureaucrat with exact grade-----" << std::endl;
        try {
            Bureaucrat exactBureaucrat("Exact", 50);  // Exactly qualified to sign

            ShrubberyCreationForm shrubberyForm("Shrubbery Form");
            std::cout << "\nBureaucrat information:\n" << exactBureaucrat;
            
            std::cout << "Form information:\n" << shrubberyForm;
            exactBureaucrat.signForm(shrubberyForm);  // Should succeed
            std::cout << "Form information:\n" << shrubberyForm;

            exactBureaucrat.executeForm(shrubberyForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Bureaucrat with highest possible grade
        std::cout << "\n-----Testing bureaucrat with top grade-----" << std::endl;
        try {
            Bureaucrat topBureaucrat("Hotshot", 1);  // Top bureaucrat

            PresidentialPardonForm presidentialForm("Presidential Pardon");
            std::cout << "\nBureaucrat information:\n" << topBureaucrat;
            
            std::cout << "Form information:\n" << presidentialForm;
            topBureaucrat.signForm(presidentialForm);  // Should succeed
            std::cout << "Form information:\n" << presidentialForm;

            topBureaucrat.executeForm(presidentialForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Testing with robotomy form for a bureaucrat with lowest grade
        std::cout << "\n-----Testing bureaucrat with lowest grade-----" << std::endl;
        try {
            Bureaucrat lowBureaucrat("Low", 150);  // Lowest grade bureaucrat

            RobotomyRequestForm robotomyForm("Robotomy Request");
            std::cout << "\nBureaucrat information:\n" << lowBureaucrat;

            std::cout << "Form information:\n" << robotomyForm;
            lowBureaucrat.signForm(robotomyForm);  // Should succeed
            std::cout << "Form information:\n" << robotomyForm;

            lowBureaucrat.executeForm(robotomyForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // A bureaucrat with mid-range grade trying to sign and execute a ShrubberyCreationForm
        try {
            Bureaucrat gardener("Gardener Greg", 100);
            ShrubberyCreationForm shrubberyForm("Garden Design Form");
            std::cout << "\nBureaucrat information:\n" << gardener;
            std::cout << "Form information:\n" << shrubberyForm;
            gardener.signForm(shrubberyForm);  // Should succeed
            std::cout << "Form information:\n" << shrubberyForm;
            gardener.executeForm(shrubberyForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;
        // Top bureaucrat signing and executing PresidentialPardonForm
        try {
            Bureaucrat president("President Pat", 1);
            PresidentialPardonForm pardonForm("High-Level Pardon");
            std::cout << "\nBureaucrat information:\n" << president;
            president.signForm(pardonForm);  // Should succeed
            president.executeForm(pardonForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Bureaucrat barely qualified to sign but not execute a RobotomyRequestForm
        try {
            Bureaucrat technician("Technician Tom", 75);
            RobotomyRequestForm robotForm("AI Upgrade Request");
            std::cout << "\nBureaucrat information:\n" << technician;
            technician.signForm(robotForm);  // Should succeed
            technician.executeForm(robotForm);  // Should fail
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Low-level bureaucrat trying to sign a high-requirement PresidentialPardonForm
        try {
            Bureaucrat intern("Intern Ian", 145);
            PresidentialPardonForm pardonForm("Confidential Pardon Request");
            std::cout << "\nBureaucrat information:\n" << intern;
            intern.signForm(pardonForm);  // Should fail
            intern.executeForm(pardonForm);  // Should fail
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // High-level bureaucrat signing but not executing a ShrubberyCreationForm
        try {
            Bureaucrat executive("Executive Eve", 20);
            ShrubberyCreationForm landscapeForm("Landscape Approval Form");
            std::cout << "\nBureaucrat information:\n" << executive;
            executive.signForm(landscapeForm);  // Should succeed
            executive.executeForm(landscapeForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Bureaucrat at grade limit for signing and executing a RobotomyRequestForm
        try {
            Bureaucrat boundaryBureaucrat("Boundary Bob", 45);
            RobotomyRequestForm experimentForm("Mechanical Arm Installation");
            std::cout << "\nBureaucrat information:\n" << boundaryBureaucrat;
            boundaryBureaucrat.signForm(experimentForm);  // Should succeed
            boundaryBureaucrat.executeForm(experimentForm);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Low-rank bureaucrat attempting to handle a high-priority PresidentialPardonForm
        try {
            Bureaucrat assistant("Assistant Andy", 130);
            PresidentialPardonForm topSecretPardon("Top-Secret Presidential Pardon");
            std::cout << "\nBureaucrat information:\n" << assistant;
            assistant.signForm(topSecretPardon);  // Should fail
            assistant.executeForm(topSecretPardon);  // Should fail
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Mid-level bureaucrat signing and executing a ShrubberyCreationForm
        try {
            Bureaucrat planner("Planner Pete", 50);
            ShrubberyCreationForm parkProject("Community Park Design");
            std::cout << "\nBureaucrat information:\n" << planner;
            planner.signForm(parkProject);  // Should succeed
            planner.executeForm(parkProject);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Elite bureaucrat signing a high-risk RobotomyRequestForm
        try {
            Bureaucrat ceo("CEO Clara", 2);
            RobotomyRequestForm labExperiment("AI Testing");
            std::cout << "\nBureaucrat information:\n" << ceo;
            ceo.signForm(labExperiment);  // Should succeed
            ceo.executeForm(labExperiment);  // Should succeed
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Low-rank bureaucrat failing to sign any form
        try {
            Bureaucrat newHire("New Hire Nancy", 150);
            ShrubberyCreationForm yardProject("Backyard Design");
            std::cout << "\nBureaucrat information:\n" << newHire;
            newHire.signForm(yardProject);  // Should fail
            newHire.executeForm(yardProject);  // Should fail
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;

        // Mid-level bureaucrat succeeding in signing, failing in executing a PresidentialPardonForm
        try {
            Bureaucrat director("Director Diana", 40);
            PresidentialPardonForm securityClearance("High-Level Clearance");
            std::cout << "\nBureaucrat information:\n" << director;
            director.signForm(securityClearance);  // Should succeed
            director.executeForm(securityClearance);  // Should fail
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Outer exception caught: " << e.what() << std::endl;
    }

    return 0;
}
