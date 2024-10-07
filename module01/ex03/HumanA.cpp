/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:03:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 17:20:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string str, Weapon &weapon) : name(str), weapon(weapon) {}

void    HumanA::attack()
{
    std::cout << name << " attacks with their "
    << weapon.getType() << std::endl;
}