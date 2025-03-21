/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:41:14 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal("Cat"), _brain(new Brain) { std::cout << "Cat created\n"; }

Cat::Cat (const Cat &to_copy) 
    : Animal(to_copy), _brain(new Brain(*to_copy._brain)) {
    std::cout << "Cat" COPY_ANIMAL << std::endl;
}

Cat::~Cat () { delete _brain; std::cout << "Cat destroyed\n"; }

Cat& Cat::operator=(const Cat &to_copy) {
    if (this == &to_copy)
        return (*this);
    delete _brain;
    _brain = new Brain(*to_copy._brain);
    std::cout << ASSIGN_ANIMAL << _type << std::endl;
    return (*this);
}

void    Cat::setIdea(std::string idea) { _brain->setIdea(idea); }

void    Cat::readMind(void) { _brain->readMind(); }

void    Cat::makeSound(void) const { std::cout << "Meow!\n"; }
