/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 10:33:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEF_ANIMAL		"The default constructor created an Animal"
#define DESTR_ANIMAL	"The destructor destroyed an Animal"
#define ASSIGN_ANIMAL	" was created using copy assignment constructor"
#define COPY_ANIMAL		" was created using copy constructor"
#define DEF_NOISES      "Default animal noises"

class Animal
{
    protected:
                std::string _type;
    public:
                Animal();                   // Default constructor
                Animal(std::string type);   // Parameterised constructor
                Animal(const Animal&);      // Copy constructor
                virtual ~Animal();          // Destructor

				Animal& operator=(const Animal&); // Assignment operator overload
				
				virtual void	makeSound(void) const;
				std::string     getType(void) const;
};