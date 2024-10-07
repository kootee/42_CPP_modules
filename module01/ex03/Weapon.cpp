/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:03:40 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 15:40:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string str) : type(str) {}

const   std::string & Weapon::getType()
{
    return (type);
}

void	Weapon::setType(std::string weapon_type)
{
	type = weapon_type;
}

