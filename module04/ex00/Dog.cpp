/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:14:57 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 09:39:40 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal() 
{
    type = "Dog";
    std::cout << DEF_ANIMAL << type << std::endl; 
}

Dog::Dog (const Dog &to_copy) : Animal(to_copy)
{
    this->type = to_copy.type;
    std::cout << this->type << COPY_ANIMAL << std::endl;
}

Dog::~Dog () { std::cout << DESTR_ANIMAL << this->type << std::endl; }

Dog& Dog::operator=(const Dog &to_copy)
{
    std::cout << to_copy.type << ASSIGN_ANIMAL << std::endl;
    if (this == &to_copy)
        return (*this);
    this->type = to_copy.type;
    return (*this);
}

void    Dog::makeSound(void) const { std::cout << "Woof woof!" << std::endl; }