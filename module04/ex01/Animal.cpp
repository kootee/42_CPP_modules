/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:02 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:57:35 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Constructors */
Animal::Animal() : _type("Default") { std::cout << DEF_ANIMAL << std::endl; };

Animal::Animal(std::string type) : _type(type) {
	std::cout << TYPE_ANIMAL << _type << std::endl; 
}

Animal::~Animal() { std::cout << DESTR_ANIMAL << _type << std::endl; };

Animal::Animal(const Animal& to_copy) : _type(to_copy._type) {
	std::cout << COPY_ANIMAL << _type << std::endl;
}

/* Operator overloads */
Animal &Animal::operator=(const Animal& to_copy)
{
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	std::cout << ASSIGN_ANIMAL << _type << std::endl;
	return (*this);
}

/* Class member functions */
void    Animal::makeSound(void) const { std::cout << DEF_NOISES << std::endl; }

std::string	Animal::getType(void) const { return (_type); }