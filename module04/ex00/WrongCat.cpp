/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:00:30 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:33:30 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat () : WrongAnimal("WrongCat") 
{ 
    std::cout << "WrongCat created" << std::endl; 
}

WrongCat::WrongCat (const WrongCat &to_copy) : WrongAnimal(to_copy)
{
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat::~WrongCat () 
{ 
    std::cout << "The destructor destroyed an animal of type "
    << this->_type << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat &to_copy)
{
    std::cout << to_copy._type << " assigned" << std::endl;
    if (this == &to_copy)
        return (*this);
    this->_type = to_copy._type;
    return (*this);
}

void    WrongCat::makeSound(void) const 
{ 
    std::cout << "Meow!" << std::endl; 
}