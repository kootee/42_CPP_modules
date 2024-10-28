/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:54:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 16:58:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
    std::cout << "Wrong animal created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
{
    std::cout << "Wrong animal copied" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& to_copy)
{
    std::cout << "Wrong animal copied with assignment operator" << std::endl;
}

void    WrongAnimal::makeSound(void)
{
    std::cout << "Wrong animal sounds" << std::endl;
}