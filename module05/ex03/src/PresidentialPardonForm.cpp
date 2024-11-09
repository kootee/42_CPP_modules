/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:27:08 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 16:25:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm(PARDONFORM, 25, 5, "default") 
{ 
    std::cout << "Default" PARDONFORM " created\n"; 
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm(PARDONFORM, 25, 5, target)
{
    std::cout << PARDONFORM " created\n"; 
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << PARDONFORM " deleted\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy) 
	: AForm(to_copy)
{
	std::cout << PARDONFORM " copied with copy constructor\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &to_copy) 
{
	(void)to_copy;
	return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLow();
    std::cout << this->getTarget() << 
    " has been pardoned by Zaphod Beeblebrox upon the request of " 
    << executor.getName() << std::endl;
}