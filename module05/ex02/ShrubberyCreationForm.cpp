/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:09:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 15:22:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm(SHRUBFORM, 145, 137, "default_shrubbery") 
{ 
    std::cout << "Default" SHRUBFORM " created\n"; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm(SHRUBFORM, 145, 137, target + "_shrubbery")
{
    std::cout << SHRUBFORM " created\n"; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << SHRUBFORM " deleted\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy) 
	: AForm(to_copy)
{
	std::cout << SHRUBFORM " copied with copy constructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &to_copy) 
{
	(void)to_copy;
	return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    std::ofstream out(this->getTarget());
    out <<  "  *     *     *     *     *     *     *  \n"
            " ***   ***   ***   ***   ***   ***   *** \n"
            "***** ***** ***** ***** ***** ***** *****\n"
            "    *      *     *     *     *     *     \n"
            "   ***    ***   ***   ***   ***   ***    \n"
            "  *****  ***** ***** ***** ***** *****   \n"
            "  *     *     *     *     *     *     *  \n"
            " ***   ***   ***   ***   ***   ***   *** \n"
            "***** ***** ***** ***** ***** ***** *****\n"
            "    *      *     *     *     *     *     \n"
            "   ***    ***   ***   ***   ***   ***    \n"
            "  *****  ***** ***** ***** ***** *****   \n"
            "  *     *     *     *     *     *     *  \n"
            " ***   ***   ***   ***   ***   ***   *** \n"
            "***** ***** ***** ***** ***** ***** *****\n";
    out.close();
}