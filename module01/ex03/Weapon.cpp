/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:03:40 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 11:21:57 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon () : _type("") {}

Weapon::Weapon (std::string str) : _type(str) {}

const   std::string & Weapon::getType() { return (_type); }

void	Weapon::setType(std::string weapon_type) { _type = weapon_type; }
