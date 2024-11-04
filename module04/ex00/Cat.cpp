/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:38:32 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal("Cat") { std::cout << "Cat created\n"; }

Cat::Cat (const Cat &to_copy) : Animal(to_copy) { 
    std::cout << COPY_ANIMAL << _type << std::endl; 
}

Cat::~Cat () { std::cout << DESTR_ANIMAL << _type << std::endl; }

Cat& Cat::operator=(const Cat &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy._type;
    std::cout << ASSIGN_ANIMAL << _type << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
