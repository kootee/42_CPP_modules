/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:51:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 09:55:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " type animal is hanging around" << std::endl;
        std::cout << i->getType() << " type animal is hanging around" << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal* wa = new WrongAnimal();
        const WrongCat* wc = new WrongCat();
        std::cout << wa->getType() << " type animal is hanging around" << std::endl;
        std::cout << wc->getType() << " type animal is hanging around" << std::endl;
        wa->makeSound();
        wc->makeSound();
        delete wa;
        delete wc;
    }
    
    return 0;
}