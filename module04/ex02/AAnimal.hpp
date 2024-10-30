/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 11:03:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEF_ANIMAL		"Animal created"
#define DESTR_ANIMAL	"Animal destroyed"
#define ASSIGN_ANIMAL	" was created using copy assignment constructor"
#define COPY_ANIMAL		" was created using copy constructor"
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
				
				virtual void	makeSound(void) const = 0; // Pure virtual class function
				std::string     getType(void) const;
};