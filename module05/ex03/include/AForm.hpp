/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:33:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 14:34:27 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define EXCEPTION_HIGH	"grade too high"
#define EXCEPTION_LOW	"grade too low"

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

	AForm& operator=(const AForm&);
	
	/* Class functions */
	std::string	getName()       const;
	std::string	getTarget()		const;
	bool	    isSigned()		const;
	int			getSignGrade()  const;
	int			getExecGrade()  const;
	
	void		beSigned(Bureaucrat const &);

	virtual void	execute(Bureaucrat const &executor) const = 0;

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

std::ostream& operator<< (std::ostream &, const AForm &);
