/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:37 by ktoivola          #+#    #+#             */
/*   Updated: 2025/01/17 14:46:55 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors */
Bureaucrat::Bureaucrat() : _grade(150), _name("Default") 
{
	std::cout << "Bureaucrat created by default constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Bureaucrat created with Name: " 
		<< name << " and Grade: " << grade << "\n";
}

/* Copy constructors */
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

/* Destructor */
Bureaucrat::~Bureaucrat() {}

/* Getters */
std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const {return (_grade); }

/* Class methods */
void    Bureaucrat::incrementGrade(void)
{
	int newGrade = _grade - 1;
	
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = newGrade;
}

void    Bureaucrat::decrementGrade(void)
{
	int newGrade = _grade + 1;
	
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = newGrade;
}

std::ostream &operator<<(std::ostream &os_object, Bureaucrat const &object)
{
	os_object << object.getName() << ", bureaucrat grade "
	<< object.getGrade() << "\n";
	return (os_object);
}

const char *Bureaucrat::GradeTooHighException::what() const throw () 
{
	return(EXCEPTION_HIGH);
}

const char *Bureaucrat::GradeTooLowException::what() const throw () 
{
	return(EXCEPTION_LOW);
}