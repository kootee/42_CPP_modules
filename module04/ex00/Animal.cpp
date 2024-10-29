/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:02 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 09:34:06 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Constructors */
Animal::Animal() : type("Default") 
{
	std::cout << DEF_ANIMAL << this->type << std::endl;
};

Animal::~Animal() 
{ 
	std::cout << DESTR_ANIMAL << this->type << std::endl;
};

Animal::Animal(const Animal& to_copy)
{
	std::cout << COPY_ANIMAL << this->type << std::endl;
	this->type = to_copy.type;
}

/* Operator overloads */
Animal &Animal::operator=(const Animal& to_copy)
{
	std::cout << ASSIGN_ANIMAL << this->type << std::endl;
	if (this == &to_copy)
		return (*this);
	this->type = to_copy.type;
	return (*this);       
}

/* Class member functions */
void    Animal::makeSound(void) const { std::cout << DEF_NOISES << std::endl; }

std::string	Animal::getType(void) const { return (this->type); }