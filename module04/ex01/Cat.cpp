/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 16:26:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal("Cat"), _brain(new Brain) { std::cout << "Cat created\n"; }

Cat::Cat (const Cat &to_copy) 
    : Animal(to_copy), _brain(new Brain(*to_copy._brain))
{
    std::cout << this->_type << COPY_ANIMAL << std::endl;
}

Cat::~Cat () 
{ 
    delete _brain;
    std::cout << DESTR_ANIMAL << _type << " and its brain" << std::endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
    std::cout << _type << ASSIGN_ANIMAL << std::endl;
    if (this == &to_copy)
        return (*this);
    Animal::operator=(to_copy);
    delete _brain;
    _brain = new Brain(*to_copy._brain);
    return (*this);
}

void    Cat::setIdea(std::string idea) { _brain->setIdea(idea); }

void    Cat::readMind(void) { _brain->readMind(); }

void    Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }