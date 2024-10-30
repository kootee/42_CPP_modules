/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:02 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 16:41:07 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Constructors */
Animal::Animal() : _type("Default") 
{
	std::cout << DEF_ANIMAL << this->_type << std::endl;
};

Animal::Animal(std::string type) : _type(type)
{
	std::cout << DEF_ANIMAL << type << std::endl;
}

Animal::~Animal() 
{ 
	std::cout << DESTR_ANIMAL << this->_type << std::endl;
};

Animal::Animal(const Animal& to_copy)
{
	std::cout << COPY_ANIMAL << this->_type << std::endl;
	this->_type = to_copy._type;
}

/* Operator overloads */
Animal &Animal::operator=(const Animal& to_copy)
{
	std::cout << _type << ASSIGN_ANIMAL << std::endl;
	if (this == &to_copy)
		return (*this);
	this->_type = to_copy._type;
	return (*this);       
}

/* Class member functions */
void    Animal::makeSound(void) const { std::cout << DEF_NOISES << std::endl; }

std::string	Animal::getType(void) const { return (this->_type); }