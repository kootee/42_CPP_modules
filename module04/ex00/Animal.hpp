/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 16:45:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEF_ANIMAL		"The default constructor created an animal of type "
#define DESTR_ANIMAL	"The destructor destroyed an animal of type "
#define ASSIGN_ANIMAL	" was created using copy assignment constructor"
#define COPY_ANIMAL		" was created using copy constructor"


class Animal
{
    protected:
                std::string type;
    public:
                Animal();               // Default constructor
                Animal(const Animal&);  // Copy constructor
                ~Animal();              // Destructor

				Animal& operator=(const Animal&); // Assignment operator overload
				
				virtual void	makeSound(void);
				std::string     getType(void);
};