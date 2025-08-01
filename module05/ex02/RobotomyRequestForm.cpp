/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:51 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 19:47:18 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm(ROBOTOFORM, 72, 45, "default") 
{ 
    std::cout << "Default" ROBOTOFORM " created\n"; 
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm(ROBOTOFORM, 72, 45, target)
{
    std::cout << ROBOTOFORM " created\n"; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << ROBOTOFORM " deleted\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy) 
	: AForm(to_copy)
{
	std::cout << ROBOTOFORM " copied with copy constructor\n";
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
    if (!this->isSigned())
        throw AForm::NotSignedException();
    static bool success = false;
    if (success)
    {
        std::cout << "*BRRRRRRRR* *BRRRRRRR* ....... " << this->getTarget() 
        << " has been succesfully robotomized\n";
    }
    else
        std::cout << this->getTarget() << ": robotomy failed\n";
    success = !success;
}