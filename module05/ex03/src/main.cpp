/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:19:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 14:47:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main() {
    try {
        Intern someRandomIntern;
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
            AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Shrubbery Form");
            std::cout << "Form information:\n" << *shrubberyForm;

            validBureaucrat.signForm(*shrubberyForm);
            std::cout << "Form information:\n" << *shrubberyForm;

            validBureaucrat.executeForm(*shrubberyForm);
            delete shrubberyForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n-----Testing PresidentialPardonForm-----" << std::endl;
        try {
            AForm* presidentialForm = someRandomIntern.makeForm("presidential pardon", "Presidential Pardon");
            std::cout << "Form information:\n" << *presidentialForm;

            validBureaucrat.signForm(*presidentialForm);
            std::cout << "Form information:\n" << *presidentialForm;

            validBureaucrat.executeForm(*presidentialForm);
            delete presidentialForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n-----Testing RobotomyRequestForm-----" << std::endl;
        try {
            AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robotomy Request");
            std::cout << "Form information:\n" << *robotomyForm;

            validBureaucrat.signForm(*robotomyForm);
            std::cout << "Form information:\n" << *robotomyForm;

            superBureaucrat.executeForm(*robotomyForm);
            superBureaucrat.executeForm(*robotomyForm);
            semisuperBureaucrat.executeForm(*robotomyForm);
            semisuperBureaucrat.executeForm(*robotomyForm);
            delete robotomyForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Additional tests with various bureaucrat grades trying to sign and execute forms
        std::cout << "\n-----Testing bureaucrat with insufficient grade-----" << std::endl;
        try {
            Bureaucrat juniorBureaucrat("Junior", 120);
            AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Shrubbery Form");
            std::cout << "\nBureaucrat information:\n" << juniorBureaucrat;
            std::cout << "Form information:\n" << *shrubberyForm;
            juniorBureaucrat.signForm(*shrubberyForm);  // Should throw exception
            juniorBureaucrat.executeForm(*shrubberyForm);  // Should throw exception
            delete shrubberyForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Bureaucrat with exact signing and executing capability
        std::cout << "\n-----Testing bureaucrat with exact grade-----" << std::endl;
        try {
            Bureaucrat exactBureaucrat("Exact", 50);
            AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Shrubbery Form");
            std::cout << "\nBureaucrat information:\n" << exactBureaucrat;
            std::cout << "Form information:\n" << *shrubberyForm;
            exactBureaucrat.signForm(*shrubberyForm);
            std::cout << "Form information:\n" << *shrubberyForm;
            exactBureaucrat.executeForm(*shrubberyForm);
            delete shrubberyForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Bureaucrat with top grade
        std::cout << "\n-----Testing bureaucrat with top grade-----" << std::endl;
        try {
            Bureaucrat topBureaucrat("Hotshot", 1);
            AForm* presidentialForm = someRandomIntern.makeForm("presidential pardon", "Presidential Pardon");
            std::cout << "\nBureaucrat information:\n" << topBureaucrat;
            std::cout << "Form information:\n" << *presidentialForm;
            topBureaucrat.signForm(*presidentialForm);
            topBureaucrat.executeForm(*presidentialForm);
            delete presidentialForm;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Testing incorrect form creation
        std::cout << "\n-----Testing Incorrect Form Creation Attempts-----" << std::endl;
        try {
            AForm* unknownForm1 = someRandomIntern.makeForm("unknown form", "Invalid Form 1");
            delete unknownForm1;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            AForm* unknownForm2 = someRandomIntern.makeForm("another invalid form", "Invalid Form 2");
            delete unknownForm2;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Outer exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n-----Testing with various bureaucrats and forms-----" << std::endl;
        Intern intern;

        // Mid-grade bureaucrat attempting to sign and execute a ShrubberyCreationForm
        try {
            Bureaucrat gardener("Gardener Greg", 100);
            AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Garden Design Form");
            std::cout << "\nBureaucrat information:\n" << gardener;
            std::cout << "Form information:\n" << *shrubberyForm;
            gardener.signForm(*shrubberyForm);  
            gardener.executeForm(*shrubberyForm);  
            delete shrubberyForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // High-ranking bureaucrat signing and executing a PresidentialPardonForm
        try {
            Bureaucrat president("President Pat", 1);
            AForm* pardonForm = intern.makeForm("presidential pardon", "High-Level Pardon");
            std::cout << "\nBureaucrat information:\n" << president;
            president.signForm(*pardonForm);  
            president.executeForm(*pardonForm);  
            delete pardonForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Bureaucrat qualified to sign but not execute a RobotomyRequestForm
        try {
            Bureaucrat technician("Technician Tom", 75);
            AForm* robotForm = intern.makeForm("robotomy request", "AI Upgrade Request");
            std::cout << "\nBureaucrat information:\n" << technician;
            technician.signForm(*robotForm);  
            technician.executeForm(*robotForm);  
            delete robotForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Low-level bureaucrat attempting to sign a high-requirement PresidentialPardonForm
        try {
            Bureaucrat internBureaucrat("Intern Ian", 145);
            AForm* pardonForm = intern.makeForm("presidential pardon", "Confidential Pardon Request");
            std::cout << "\nBureaucrat information:\n" << internBureaucrat;
            internBureaucrat.signForm(*pardonForm);  
            internBureaucrat.executeForm(*pardonForm);  
            delete pardonForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // High-ranking bureaucrat signing and executing a ShrubberyCreationForm
        try {
            Bureaucrat executive("Executive Eve", 20);
            AForm* landscapeForm = intern.makeForm("shrubbery creation", "Landscape Approval Form");
            std::cout << "\nBureaucrat information:\n" << executive;
            executive.signForm(*landscapeForm);  
            executive.executeForm(*landscapeForm);  
            delete landscapeForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Bureaucrat at grade limit for signing and executing a RobotomyRequestForm
        try {
            Bureaucrat boundaryBureaucrat("Boundary Bob", 45);
            AForm* experimentForm = intern.makeForm("robotomy request", "Mechanical Arm Installation");
            std::cout << "\nBureaucrat information:\n" << boundaryBureaucrat;
            boundaryBureaucrat.signForm(*experimentForm);  
            boundaryBureaucrat.executeForm(*experimentForm);  
            delete experimentForm;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Low-rank bureaucrat attempting to sign and execute a high-priority PresidentialPardonForm
        try {
            Bureaucrat assistant("Assistant Andy", 130);
            AForm* topSecretPardon = intern.makeForm("presidential pardon", "Top-Secret Presidential Pardon");
            std::cout << "\nBureaucrat information:\n" << assistant;
            assistant.signForm(*topSecretPardon);  
            assistant.executeForm(*topSecretPardon);  
            delete topSecretPardon;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Mid-level bureaucrat signing and executing a ShrubberyCreationForm
        try {
            Bureaucrat planner("Planner Pete", 50);
            AForm* parkProject = intern.makeForm("shrubbery creation", "Community Park Design");
            std::cout << "\nBureaucrat information:\n" << planner;
            planner.signForm(*parkProject);  
            planner.executeForm(*parkProject);  
            delete parkProject;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Elite bureaucrat signing and executing a high-risk RobotomyRequestForm
        try {
            Bureaucrat ceo("CEO Clara", 2);
            AForm* labExperiment = intern.makeForm("robotomy request", "AI Testing");
            std::cout << "\nBureaucrat information:\n" << ceo;
            ceo.signForm(*labExperiment);  
            ceo.executeForm(*labExperiment);  
            delete labExperiment;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Low-rank bureaucrat failing to sign or execute any form
        try {
            Bureaucrat newHire("New Hire Nancy", 150);
            AForm* yardProject = intern.makeForm("shrubbery creation", "Backyard Design");
            std::cout << "\nBureaucrat information:\n" << newHire;
            newHire.signForm(*yardProject);  
            newHire.executeForm(*yardProject);  
            delete yardProject;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Mid-level bureaucrat succeeding in signing, failing in executing a PresidentialPardonForm
        try {
            Bureaucrat director("Director Diana", 40);
            AForm* securityClearance = intern.makeForm("presidential pardo", "High-Level Clearance");
            std::cout << "\nBureaucrat information:\n" << director;
            director.signForm(*securityClearance);
            director.executeForm(*securityClearance);
            delete securityClearance;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
