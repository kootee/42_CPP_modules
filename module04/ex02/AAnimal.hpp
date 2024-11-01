/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:58:41 by ktoivola         ###   ########.fr       */
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

class AAnimal
{
    protected:
                std::string _type;
    public:
                AAnimal();                   // Default constructor
                AAnimal(std::string type);   // Parameterised constructor
                AAnimal(const AAnimal&);     // Copy constructor
                virtual ~AAnimal() = 0;      // Pure virtual Destructor

				AAnimal& operator=(const AAnimal&); // Assignment operator overload
				
				virtual void	    makeSound(void) const = 0; // Pure virtual class function
				std::string         getType(void) const;
};