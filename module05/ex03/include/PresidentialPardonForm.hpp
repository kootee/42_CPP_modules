/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:25:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/07 16:03:54 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PARDONFORM "PresidentialPardonForm"

/*  Needs to be implemented from the base class:
        - execute(Bureaucrat)
    Inherits following private attributes:
        _name;
        _signed;
        _sign_grade;
        _exec_grade;    */

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm&);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm&);

    /* Class member functions */
    void    execute(Bureaucrat const &) const override;
};