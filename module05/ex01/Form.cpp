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

/* Constructors */
Form::Form() 
	: 	_name("Default form"), 
		_signed(false), 
		_signGrade(1), 
		_execGrade(1)
{
	std::cout << "Default Form created with Sign Grade" << 1 
			<< " and Excec Grade: " << 1 << "\n";
}

Form::Form(std::string name, int signGrade, int execGrade) 
	:   _name(name), 
		_signed(false), 
		_signGrade(signGrade), 
		_execGrade(execGrade)
{
	if (signGrade < 1)
		throw Form::GradeTooHigh();
	if (signGrade > 150)
		throw Form::GradeTooLow();
	if (execGrade < 1)
		throw Form::GradeTooHigh();
	if (execGrade > 150)
		throw Form::GradeTooLow();
	std::cout << "Form created with Name: " << name 
			<< " | Sign Grade: " << signGrade 
			<< " | Excec Grade: " << execGrade << "\n";
}

/* Copy constructors */
Form::Form(const Form &to_copy) 
	:	_name(to_copy._name), 
		_signed(to_copy._signed), 
		_signGrade(to_copy._signGrade), 
		_execGrade(to_copy._execGrade)
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

/* Destructor */
Form::~Form() {}

/* Getters */
std::string Form::getName() const { return (_name); }

bool	Form::isSigned() const { return (_signed); }

int		Form::getSignGrade() const {return (_signGrade); }

int		Form::getExecGrade() const {return (_execGrade); }

/* Class methods */
void	Form::beSigned(Bureaucrat const &signee) 
{
	if (signee.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLow();
	_signed = true;
}

/* Insertion operator overload */
std::ostream & operator<<(std::ostream &os_object, Form const &object)
{
	std::string signed_status = (object.isSigned()) ? "signed" : "unsigned";
	
	os_object << "This " << signed_status 
	<< " form called " << object.getName() 
	<< " has a sign grade of " << object.getSignGrade() 
	<< " and a excecute grade of " << object.getExecGrade()
	<< "\n";
	return (os_object);
}

/* Exceptions */
const char *Form::GradeTooHigh::what() const throw () 
{
	return(EXCEPTION_HIGH);
}

const char *Form::GradeTooLow::what() const throw () 
{
	return(EXCEPTION_LOW);
}