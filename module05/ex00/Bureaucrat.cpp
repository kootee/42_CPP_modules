/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/04 16:43:03 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade)
{
    if (grade < 1 || grade > 150)
        throw this->GradeTooHigh();
}

Bureaucrat::~Bureaucrat()
{
}


void    Bureaucrat::GradeTooHigh() 
{
    
}

void    Bureaucrat::GradeTooLow() {
    
}