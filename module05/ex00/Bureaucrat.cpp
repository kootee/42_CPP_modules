/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/04 17:39:31 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Default") 
{
    std::cout << "Bureaucrat created by default constructor\n";
}

Bureaucrat::Bureaucrat(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHigh;
    else if (grade > 150)
        throw Bureaucrat::GradeTooLow;
    std::cout << "Bureaucrat created with parameterized constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) 
    : _grade(to_copy._grade), _name(to_copy._name) 
{
    std::cout << "Bureaucrat copied with copy constructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_copy) 
{
    if (this == &to_copy)
        return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destroyed\n"; }

void    Bureaucrat::GradeTooHigh() 
{
    std::cout << "Error thrown; grade too high (highest is 1)\n";
}

void    Bureaucrat::GradeTooLow() 
{
    std::cout << "Error thrown; grade too low (lowest is 150)\n";
}

std::string Bureaucrat::getName(void) { return (_name); }

int Bureaucrat::getGrade(void) {return (_grade); }

void    Bureaucrat::incrementGrade(void)
{
    int temp = _grade - 1;
    
    if (temp < 1)
        throw Bureaucrat::GradeTooHigh;
    else
        _grade = temp;
}

void    Bureaucrat::decrementGrade(void)
{
    int temp = _grade + 1;
    
    if (temp > 150)
        throw Bureaucrat::GradeTooLow;
    else
        _grade = temp;
}

std::ostream & operator<<(std::ostream &os_object, const Bureaucrat &object)
{
    
}