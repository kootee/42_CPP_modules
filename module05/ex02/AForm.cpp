/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:28 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 16:25:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: 	_name("Default Form"),
		_target("Default target"),
		_sign_grade(1), 
		_exec_grade(1),
		_signed(false) 
{
	std::cout << "Form created by default constructor\n";
}

AForm::AForm(std::string name, int sign_grade, int exec_grade, std::string target) 
	:   _name(name), 
		_target(target),
		_sign_grade(sign_grade), 
		_exec_grade(exec_grade),
		_signed(false)
{
	if (sign_grade < 1)
		throw AForm::GradeTooHigh();
	else if (sign_grade > 150)
		throw AForm::GradeTooLow();
	if (exec_grade < 1)
		throw AForm::GradeTooHigh();
	else if (exec_grade > 150)
		throw AForm::GradeTooLow();
	std::cout << "Form created with parameterized constructor\n";
}

/* Destructor */
AForm::~AForm() { std::cout << "Form destroyed\n"; }

/* Copy constructors */
AForm::AForm(const AForm &to_copy) 
	:   _name(to_copy._name), 
		_target(to_copy._target),
		_sign_grade(to_copy._sign_grade), 
		_exec_grade(to_copy._exec_grade),
		_signed(to_copy._signed)
{
	std::cout << "Form copied with copy constructor\n";
}

AForm &AForm::operator=(const AForm &to_copy) 
{
	if (this == &to_copy)
		return (*this);
	this->_signed = to_copy._signed;
	return (*this);
}

/* Class functions */
std::string AForm::getName() const { return (_name); }

std::string	AForm::getTarget() const {return (_target); }

bool	AForm::isSigned() const { return (_signed); }

int		AForm::getSignGrade() const {return (_sign_grade); }

int		AForm::getExecGrade() const {return (_exec_grade); }


void	AForm::beSigned(Bureaucrat const &signee) 
{
	if (signee.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLow();
	_signed = true;
}

std::ostream & operator<<(std::ostream &os_object, AForm const &object)
{
	std::string signed_status = (object.isSigned()) ? "signed" : "unsigned";
	
	os_object 
	<< "This " << signed_status << " " << object.getName() 
	<< " has a sign grade of " << object.getSignGrade() 
	<< " and a excecute grade of " << object.getExecGrade()
	<< " and has the target " << object.getTarget()
	<< std::endl;
	return (os_object);
}