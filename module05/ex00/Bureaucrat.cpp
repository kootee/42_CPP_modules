/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/05 15:56:59 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Default") 
{
    std::cout << "Bureaucrat created by default constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHigh;
    else if (grade > 150)
        throw Bureaucrat::GradeTooLow;
    else
        _grade = grade;
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
    this->_grade = to_copy._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destroyed\n"; }

/* Exceptions */
const char* GradeTooLow::what() const
{
    return("Error thrown; grade too low (lowest is 150)");
}

const char* GradeTooHigh::what() const
{
    return("Error thrown; grade too high (highest is 1)");
}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const {return (_grade); }

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

std::ostream & operator<<(std::ostream &os_object, Bureaucrat const &object)
{
    os_object << object.getName() 
    << ", bureaucrat grade "
    << object.getGrade()
    << "\n";
    return (os_object);
}
