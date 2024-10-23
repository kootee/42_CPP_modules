/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:33:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:42 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    // set points 100 50 30
    std::cout << "DiamondTrap constructor created " 
    << this->_name << std::endl;
    
}

DiamondTrap::DiamondTrap(const DiamondTrap& to_copy)
: ClapTrap(to_copy), FragTrap(to_copy), ScavTrap(to_copy)
{
    _name = to_copy._name;
    std::cout << _name << "DiamondTrap was created by copy constructor" 
    << std::endl;
}

DiamondTrap::~ClapTrap

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My ClapTrap name is " << this->_name;
}