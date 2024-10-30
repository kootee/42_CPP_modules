/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:02 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 10:53:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* Constructors */
AAnimal::AAnimal() : _type("Default") { std::cout << DEF_ANIMAL << std::endl; };

AAnimal::AAnimal(std::string type) : _type(type) { std::cout << DEF_ANIMAL << std::endl; }

AAnimal::~AAnimal() { std::cout << DESTR_ANIMAL << std::endl; };

AAnimal::AAnimal(const AAnimal& to_copy)
{
	std::cout << "An animal" COPY_ANIMAL << std::endl;
	this->_type = to_copy._type;
}

/* Operator overloads */
AAnimal &AAnimal::operator=(const AAnimal& to_copy)
{
	std::cout << "An animal " ASSIGN_ANIMAL << std::endl;
	if (this == &to_copy)
		return (*this);
	this->_type = to_copy._type;
	return (*this);       
}

/* Class member functions */
void    AAnimal::makeSound(void) const { std::cout << DEF_NOISES << std::endl; }

std::string	AAnimal::getType(void) const { return (this->_type); }