/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:33:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 14:53:47 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

#define EXCEPTION_HIGH	"grade too high (highest is 1)"
#define EXCEPTION_LOW	"grade too low (lowest is 150)"

class Bureaucrat;

class AForm {
private:
    std::string const   _name;
	std::string const	_target;
    int const           _sign_grade;
    int const           _exec_grade;
    bool                _signed;
public:
    AForm();
	AForm(std::string, int, int, std::string);
	AForm(const AForm&);
	~AForm();

	AForm& operator=(const AForm&) = delete;
	
	/* Class functions */
	std::string	getName()       const;
	std::string	getTarget()		const;
	bool	    isSigned()		const;
	int			getSignGrade()  const;
	int			getExecGrade()  const;
	
	void		beSigned(Bureaucrat const &);

	virtual void	execute(Bureaucrat const &) const = 0;

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
