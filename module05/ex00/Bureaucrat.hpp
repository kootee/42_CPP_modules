/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/05 15:54:21 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

/*  
	Orthodox canonical form:
		Default Constructor
		Parameterized Constructor
		Copy Constructor
		Assignment Operator
		Destructor      */

class Bureaucrat
{
private:
	int                 _grade;
	std::string const   _name;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat&);

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

	class GradeTooHigh : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLow : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
};

std::ostream& operator<< (std::ostream &, const Bureaucrat &); // Output operator overload
