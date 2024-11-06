/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:33:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 16:25:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define EXCEPTION_HIGH	"grade too high (highest is 1)"
#define EXCEPTION_LOW	"grade too low (lowest is 150)"

class Bureaucrat;

class Form {
private:
    std::string const   _name;
    bool                _signed;
    int const           _sign_grade;
    int const           _exec_grade;
public:
    Form();
	Form(std::string, int, int);
	Form(const Form&);
	~Form();

	Form& operator=(const Form&);
	
	/* Class functions */
	std::string	getName()       const;
	bool	    isSigned()		const;
	int			getSignGrade()  const;
	int			getExecGrade()  const;
	
	void		beSigned(Bureaucrat const &);

	/* Exceptions */
    class GradeTooHigh : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_LOW);	
			}
	};
	class GradeTooLow : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_HIGH);
			}
	};
};

std::ostream& operator<< (std::ostream &, const Form &);
