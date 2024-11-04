/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:14:57 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:38:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal("Dog") { std::cout << "Dog created\n"; }

Dog::Dog (const Dog &to_copy) : Animal(to_copy) { 
    std::cout << COPY_ANIMAL << _type << std::endl; 
}

Dog::~Dog () { std::cout << DESTR_ANIMAL << _type << std::endl; }

Dog& Dog::operator=(const Dog &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy._type;
    std::cout << ASSIGN_ANIMAL << _type << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const { std::cout << "Woof woof!" << std::endl; }