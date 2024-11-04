/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/04 17:04:36 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

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
    std::string const   _name;
    int                 _grade;
public:
    Bureaucrat();
    Bureaucrat(int grade);
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat&);

    void        GradeTooHigh();
    void        GradeTooLow();
    std::string getName();
    int         getGrade();
    void        incrementGrade();
    void        decrementGrade();
};

std::ostream& operator<< (std::ostream &, const Bureaucrat &); // Output operator overload
