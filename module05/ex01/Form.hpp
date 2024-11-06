/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:33:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 14:58:16 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#define EXCEPTION_HIGH	"grade too high (highest is 1)"
#define EXCEPTION_LOW	"grade too low (lowest is 150)"

class Form
{
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
/* Same as before, write getters for all attributes and an overload 
of the insertion («) operator that prints all the 
form’s informations. */
	bool	    isSigned();
	std::string	getName()       const;
	int			getSignGrade()  const;
	int			getExecGrade()  const;

	Form& operator=(const Form&);

    	class GradeTooHigh : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_LOW);	
			}
	};
	/* Exceptions */
	class GradeTooLow : public std::exception
	{
		public:
			const char* what() const noexcept override {
    			return(EXCEPTION_HIGH);
			}
	};
};

std::ostream& operator<< (std::ostream &, const Form &);
