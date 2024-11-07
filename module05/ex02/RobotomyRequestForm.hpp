/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotoMyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 15:14:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define ROBOTOFORM "RobotomyRequestForm"

/*  Needs to be implemented from the base class:
        - execute(Bureaucrat)
    Inherits following private attributes:
        _name;
        _signed;
        _sign_grade;
        _exec_grade;

Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> 
has been robotomized successfully 50% of the time. 
Otherwise, informs that the robotomy failed. */

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm&);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm&);

    /* Class member functions */
    void    execute(Bureaucrat const &);
};