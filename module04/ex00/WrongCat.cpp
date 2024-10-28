/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:00:30 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 17:02:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat () : WrongAnimal() 
{ 
    type = "WrongCat";
    std::cout << type << "created" << std::endl; 
}

WrongCat::WrongCat (const WrongCat &to_copy) : WrongAnimal(to_copy)
{
    this->type = to_copy.type;
    std::cout << this->type << "copied" << std::endl;
}

WrongCat::~WrongCat () { std::cout << "destroyed" << this->type << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat &to_copy)
{
    std::cout << to_copy.type << "assigned" << std::endl;
    if (this == &to_copy)
        return (*this);
    this->type = to_copy.type;
    return (*this);
}

void    WrongCat::makeSound(void) { std::cout << "Meow!" << std::endl; }