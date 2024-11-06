/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:28 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 16:25:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: 	_name("Default form"), 
		_signed(false), 
		_sign_grade(1), 
		_exec_grade(1)
{
	std::cout << "Form created by default constructor\n";
}

Form::Form(std::string name, int sign_grade, int exec_grade) 
	:   _name(name), 
		_signed(false), 
		_sign_grade(sign_grade), 
		_exec_grade(exec_grade)
{
	if (sign_grade < 1)
		throw Form::GradeTooHigh();
	else if (sign_grade > 150)
		throw Form::GradeTooLow();
	if (exec_grade < 1)
		throw Form::GradeTooHigh();
	else if (exec_grade > 150)
		throw Form::GradeTooLow();
	std::cout << "Form created with parameterized constructor\n";
}

Form::Form(const Form &to_copy) 
	:    _name(to_copy._name), 
		_signed(to_copy._signed), 
		_sign_grade(to_copy._sign_grade), 
		_exec_grade(to_copy._exec_grade)
{
	std::cout << "Form copied with copy constructor\n";
}

Form &Form::operator=(const Form &to_copy) 
{
	if (this == &to_copy)
		return (*this);
	this->_signed = to_copy._signed;
	return (*this);
}

Form::~Form() { std::cout << "Form destroyed\n"; }

/* Class functions */
std::string Form::getName() const { return (_name); }

bool	Form::isSigned() const { return (_signed); }

int		Form::getSignGrade() const {return (_sign_grade); }

int		Form::getExecGrade() const {return (_exec_grade); }

void	Form::beSigned(Bureaucrat const &signee) 
{
	if (signee.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLow();
	_signed = true;
}

std::ostream & operator<<(std::ostream &os_object, Form const &object)
{
	std::string signed_status = (object.isSigned()) ? "signed" : "unsigned";
	
	os_object << "This " << signed_status 
	<< " form called " << object.getName() 
	<< " has a sign grade of " << object.getSignGrade() 
	<< " and a excecute grade of " << object.getExecGrade()
	<< std::endl;
	return (os_object);
}