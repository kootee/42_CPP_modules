/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:28 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/06 08:41:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Your average form"), _signed(false)
{
    std::cout << "Form created by default constructor\n";
}

Form::Form(std::string name, int grade) : _name(name), _signed(false)
{
    if (grade < 1)
        throw Form::GradeTooHigh();
    else if (grade > 150)
        throw Form::GradeTooLow();
    else
        _grade = grade;
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

