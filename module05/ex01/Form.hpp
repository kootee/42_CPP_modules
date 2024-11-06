/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:33:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 08:43:52 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Form
{
private:
    std::string const   _name;
    bool                _signed;
    int const           _sign_level;
    int const           _exec_level;
public:
    Form();
	Form(std::string name, int grade);
	Form(const Form&);
	~Form();

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

Form::Form(/* args */)
{
}

Form::~Form()
{
}
