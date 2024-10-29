/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:54:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 09:56:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong")
{
    std::cout << "Wrong animal created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The destructor destroyed an animal of type "
    << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
{
    std::cout << "Wrong animal copied" << std::endl;
    this->type = to_copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& to_copy)
{
    std::cout << "Wrong animal copied with assignment operator" << std::endl;
	if (this == &to_copy)
		return (*this);
	this->type = to_copy.type;
	return (*this); 
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong animal sounds" << std::endl;
}

std::string	WrongAnimal::getType(void) const { return (this->type); }