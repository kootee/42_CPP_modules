/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:33:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 12:17:57 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    _name = "Default";
    ClapTrap::_name = _name + "_clap_trap";
    _hp = FragTrap::_hp;
    _ep = ScavTrap::_ep;
    _at = FragTrap::_at;
    std::cout << DT_DEFAULT_CONST << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
    :   ClapTrap(name), 
        ScavTrap(name), 
        FragTrap(name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_trap";
    _hp = FragTrap::_hp;
    _ep = ScavTrap::_ep;
    _at = FragTrap::_at;
    std::cout << _name << DT_PARAM_CONST << std::endl;
    
}

DiamondTrap::DiamondTrap(const DiamondTrap& to_copy)
    :   ClapTrap(to_copy), 
        ScavTrap(to_copy),
        FragTrap(to_copy)
{
    _name = to_copy._name;
    std::cout << _name << DT_COPY_CONST << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_at = obj._at;
	}
	std::cout << obj._name << DT_COPY_ASSIGN << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap () { std::cout << _name << DT_DESTRUCTOR << std::endl; }

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << _name 
    << " and my ClapTrap name is " << ClapTrap::_name <<
    std::endl;
}