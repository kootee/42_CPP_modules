/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:23:51 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 16:23:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define SHRUBFORM "ShrubberyCreationForm"

/*  Needs to be implemented from the base class:
        - execute(Bureaucrat)
    Inherits following private attributes:
        _name;
        _signed;
        _sign_grade;
        _exec_grade;    */

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();

    /* Class member functions */
    void    execute(Bureaucrat const &) const override;
};