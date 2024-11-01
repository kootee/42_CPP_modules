/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:39:40 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEF_ANIMAL		"The default constructor created an animal"
#define TYPE_ANIMAL     "The animal constructor created an animal of type "
#define DESTR_ANIMAL	"The destructor destroyed an animal of type "
#define ASSIGN_ANIMAL	"The assign operator copied a "
#define COPY_ANIMAL		"The copy constructor copied a "
#define DEF_NOISES      "Default animal noises"

class Animal
{
	protected:
				std::string _type;
	public:
				Animal();						// Default constructor
				Animal(std::string const type);	// Parameterised constructor
				Animal(const Animal&);			// Copy constructor
				virtual ~Animal();				// Destructor

				Animal& operator=(const Animal&); // Assignment operator overload
				
				virtual void	makeSound(void) const;
				std::string     getType(void) const;
};