/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:14:57 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:41:19 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal("Dog"), _brain(new Brain) { std::cout << "Dog created\n"; }

Dog::Dog (const Dog &to_copy) 
    :   Animal(to_copy), _brain(new Brain(*to_copy._brain)) { 
    std::cout << "Dog" COPY_ANIMAL << std::endl; 
}

Dog::~Dog () { delete _brain; std::cout << "Dog destroyed\n"; }

Dog& Dog::operator=(const Dog &to_copy) {
    if (this == &to_copy)
        return (*this);
    delete _brain;
    _brain = new Brain(*to_copy._brain);
    std::cout << ASSIGN_ANIMAL << _type << std::endl;
    return (*this);
}

void    Dog::setIdea(std::string idea) { _brain->setIdea(idea); }

void    Dog::readMind(void) { _brain->readMind(); }

void    Dog::makeSound(void) const { std::cout << "Woof woof!\n"; }