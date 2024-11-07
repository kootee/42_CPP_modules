/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:51 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 16:25:16 by ktoivola         ###   ########.fr       */
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

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &to_copy) 
{
	(void)to_copy;
	return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLow();
    static bool success = false;
    std::cout << "*BRRRRRRRR* *BRRRRRRR*\n";
    if (success)
        std::cout << this->getTarget() << " has been succesfully robotomized\n";
    else
        std::cout << this->getTarget() << " robotomy unsuccessfull\n";
    success = !success;
}