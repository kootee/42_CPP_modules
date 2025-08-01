/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:14 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/09 14:17:22 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

#define INTERNEXCEPT    "No such form exists"
#define SHRUBREQUEST    "shrubbery creation"
#define ROBOTOREQUEST   "robotomy request"
#define PARDONREQUEST   "presidential pardon"

class Intern {
public:
    Intern();
	Intern(const Intern&) = delete;
	~Intern();

	Intern& operator=(const Intern&) = delete;

    /* Class member functions */
    AForm    *makeForm(std::string name, std::string target);
	
    /* Exceptions */
    class NoSuchForm : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

