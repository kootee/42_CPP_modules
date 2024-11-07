/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 19:28:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

#define EXCEPTION_HIGH	"grade too high (highest is 1)"
#define EXCEPTION_LOW	"grade too low (lowest is 150)"

/*  
	Orthodox canonical form:
		Default Constructor
		Parameterized Constructor
		Copy Constructor
		Assignment Operator
		Destructor      */

class Form;

class Bureaucrat {
private:
	int                 _grade;
	std::string const   _name;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat&);

	/* Class functions */
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	
	void		signForm(Form &);

	/* Exceptions */
	class GradeTooHigh : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_HIGH);	
			}
	};
	class GradeTooLow : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_LOW);
			}
	};
};

std::ostream& operator<< (std::ostream &, const Bureaucrat &);