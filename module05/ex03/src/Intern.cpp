/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:40:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 14:44:22 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() { std::cout << "Anonymous Intern created\n"; }

Intern::~Intern() { std::cout << "Intern destroyed\n"; }

AForm    *Intern::makeForm(std::string formName, std::string target) {
    AForm *form;
    std::string form_types[3] = {SHRUBREQUEST, ROBOTOREQUEST, PARDONREQUEST};
    
    int index = 0;
    while (index < 3) 
    {
        if (form_types[index] == formName)
            break;
        index++;
    }
    switch (index) {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        break;
    default:
        throw Intern::NoSuchForm();
    }
    std::cout << "The intern successfully created the " 
    << formName << " form\n";
    return (form);
}