/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotoMyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 16:04:24 by ktoivola         ###   ########.fr       */
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
*/

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm&);
    ~RobotomyRequestForm();

    /* Class member functions */
    void    execute(Bureaucrat const &) const override;
};