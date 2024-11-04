/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:02 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:59:02 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* Constructors */
AAnimal::AAnimal() : _type("Default") { std::cout << DEF_ANIMAL << std::endl; };

AAnimal::AAnimal(std::string type) : _type(type) { 
	std::cout << TYPE_ANIMAL << _type << std::endl;
}

AAnimal::~AAnimal() { std::cout << DESTR_ANIMAL << std::endl; };

AAnimal::AAnimal(const AAnimal& to_copy) : _type(to_copy._type) { 
	std::cout << COPY_ANIMAL << _type << std::endl;
}

/* Operator overloads */
AAnimal &AAnimal::operator=(const AAnimal& to_copy)
{
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	std::cout << ASSIGN_ANIMAL << _type << std::endl;
	return (*this);     
}

std::string	AAnimal::getType(void) const { return (_type); }