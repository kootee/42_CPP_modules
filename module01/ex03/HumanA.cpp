/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:03:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 11:16:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string str, Weapon &weapon) : _name(str), _weapon(weapon) {}

void    HumanA::attack()
{
    std::cout << _name << " attacks with their "
    << _weapon.getType() << std::endl;
}