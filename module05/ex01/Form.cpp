/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:28 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 08:51:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Your average form"), _signed(false)
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
    : _name(to_copy._name), _signed(to_copy._signed)
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

