/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:07:38 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 17:42:02 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name) : name(name), weapon(new Weapon("")) {}

void    HumanB::attack()
{
    std::cout << name << " attacks with their "
    << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& newWeapon)
{
    this->weapon = &newWeapon;
}