/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:11:06 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 15:22:35 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    
    IMateriaSource* src = new MateriaSource(); 
    IMateriaSource* src2 = new MateriaSource(); 

    std::cout << "------- Learning 4 new materias -------\n";

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    
    std::cout << "------- Trying to learn a fifth materia -------\n";

    src->learnMateria(new Cure());
    
    std::cout << "------- Creating character 'me' -------\n";

    ICharacter* me = new Character("me");
    AMateria* tmp;
   
    std::cout << "------- Creating materias and equipping -------\n";
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    std::cout << "------- Trying to equip a fifth materia -------\n";
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    std::cout << "------- Creating character bob -------\n";
    ICharacter* bob = new Character("bob");

    std::cout << "------- Using materias on bob -------\n";
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    std::cout << "------- Unequipping materias -------\n";
    me->unequip(2);
    me->unequip(2);
    me->unequip(0);
    me->unequip(1);
    me->unequip(4);
    me->unequip(-65);
    me->unequip(3);

    std::cout << "------- Destroying materias and characters -------\n";
    delete bob; 
    delete me; 
    delete src;
    delete src2;

    return 0; 
}