/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:07:38 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 11:29:16 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name), _weapon(nullptr) {}

void    HumanB::attack()
{
    std::cout << _name << " attacks with their ";
    if (this->_weapon)
        std::cout << _weapon->getType() << std::endl;
    else
		std::cout << "bare hands" << std::endl;
}

void    HumanB::setWeapon(Weapon& newWeapon)
{
    this->_weapon = &newWeapon;
}