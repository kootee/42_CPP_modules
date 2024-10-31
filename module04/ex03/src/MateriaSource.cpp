/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:26:45 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 15:18:40 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _materiaInventory[i] = nullptr;
    std::cout << "MateriaSource created\n"; 
}

MateriaSource::MateriaSource(const MateriaSource &to_copy) {
    std::cout << "MateriaSource copied with copy constructor\n";
    for (int i = 0; i < 4; i++)
    {
        if (_materiaInventory[i])
            delete _materiaInventory[i];
        if (to_copy._materiaInventory[i])
            _materiaInventory[i] = to_copy._materiaInventory[i]->clone();
        else
            _materiaInventory[i] = nullptr;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &to_copy) {
    if (this == &to_copy)
        return (*this);
    for (int i = 0; i < 4; i++) {
        if (_materiaInventory[i])
            delete _materiaInventory[i];
        if (to_copy._materiaInventory[i])
            _materiaInventory[i] = to_copy._materiaInventory[i]->clone();
        else
            _materiaInventory[i] = nullptr;
    }
    std::cout << "MateriaSource copied with assign operator\n";
    return (*this);
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materiaInventory[i]) {
            delete _materiaInventory[i];
            _materiaInventory[i] = nullptr;
        }
    }
    std::cout << "Materia source deleted\n";
}

void    MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_materiaInventory[i]) {
            _materiaInventory[i] = m->clone();
            delete m;
            return ;
        }
    }
    delete m;
    std::cout << "No space left in inventory, materia deleted\n";
}

AMateria *MateriaSource::createMateria(std::string const &materiaName) {
    for (int i = 0; i < 4; i++) {
        if (_materiaInventory[i] != nullptr) {
            if ( _materiaInventory[i]->getType() == materiaName) {
                return (_materiaInventory[i]->clone());
            }
        }
    }
    std::cout << "No such materia learnt, can't create materia\n";
    return nullptr;
}