/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 10:59:45 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal("Cat") 
{ 
    std::cout << "Cat created" << std::endl; 
}

Cat::Cat (const Cat &to_copy) : Animal(to_copy)
{
    this->_type = to_copy._type;
    std::cout << this->_type << COPY_ANIMAL << std::endl;
}

Cat::~Cat () { std::cout << DESTR_ANIMAL << this->_type << std::endl; }

Cat& Cat::operator=(const Cat &to_copy)
{
    std::cout << to_copy._type << ASSIGN_ANIMAL << std::endl;
    if (this == &to_copy)
        return (*this);
    this->_type = to_copy._type;
    return (*this);
}

void    Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
