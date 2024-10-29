/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:14:57 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 10:59:17 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal("Dog") 
{
    std::cout << "Dog created" << std::endl; 
}

Dog::Dog (const Dog &to_copy) : Animal(to_copy)
{
    this->_type = to_copy._type;
    std::cout << this->_type << COPY_ANIMAL << std::endl;
}

Dog::~Dog () { std::cout << DESTR_ANIMAL << this->_type << std::endl; }

Dog& Dog::operator=(const Dog &to_copy)
{
    std::cout << to_copy._type << ASSIGN_ANIMAL << std::endl;
    if (this == &to_copy)
        return (*this);
    this->_type = to_copy._type;
    return (*this);
}

void    Dog::makeSound(void) const { std::cout << "Woof woof!" << std::endl; }