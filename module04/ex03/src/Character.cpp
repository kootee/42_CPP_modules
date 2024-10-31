/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:34:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 15:08:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
    std::cout << _name << " character created\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = nullptr;
}

Character::Character(const Character &to_copy) : _name(to_copy._name) {
    std::cout << "Character copied with copy constructor\n";
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] != nullptr)
            delete _inventory[i];
        if (to_copy._inventory[i])
            _inventory[i] = to_copy._inventory[i]->clone();
        else
            _inventory[i] = nullptr;
    }
}

Character& Character::operator=(const Character &to_copy) {
    if (this == &to_copy)
        return (*this);
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != nullptr)
            delete _inventory[i];
        if (to_copy._inventory[i])
            _inventory[i] = to_copy._inventory[i]->clone();
        else
            _inventory[i] = nullptr;
    }
    std::cout << "Character copied with assign operator\n";
    return (*this);
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
    }
    _oldMateria.deleteAllMateria();
    std::cout << "Destroyed character " << _name << std::endl;
}

/* Class member functions */
std::string const &Character::getName(void) const { return (_name); }

void    Character::equip(AMateria *m) {
    if (m == nullptr)
        return ;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == nullptr) {
            _inventory[i] = m;
            std::cout << m->getType() << " materia equipped in slot " 
            << i << std::endl;
            return ;
        }
    }
    std::cout << "No space left in inventory, materia deleted\n";
    delete m;
}

void    Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || _inventory[idx] == nullptr)
        std::cout << "Invalid materia index\n";
    else
        _inventory[idx]->use(target);
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || _inventory[idx] == nullptr)
        std::cout << "Invalid materia index\n";
    else {
        std::cout << _inventory[idx]->getType() << " from slot "<< idx 
        << " unequipped\n";
        _oldMateria.insertMateria(_inventory[idx]);
        _inventory[idx] = nullptr;
    }
}