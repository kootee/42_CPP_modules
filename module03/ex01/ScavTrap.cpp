/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/25 10:42:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap()
{
    _hp = 100;
    _ep = 50;
    _at = 20;
    std::cout << ST_DEFAULT_CONST << std::endl;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 50;
    _at = 20;
    std::cout << _name << ST_PARAM_CONST << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << _name << ST_DESTRUCTOR << std::endl; }

ScavTrap::ScavTrap (const ScavTrap &obj)
{
	_name = obj._name;
	_hp = obj._hp;
	_ep = obj._ep;
	_at = obj._at;
	std::cout << obj._name <<  ST_COPY_CONST << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_at = obj._at;
	}
	std::cout << obj._name << ST_COPY_ASSIGN << std::endl;
	return (*this);
}

/* Class member functions */
void    ScavTrap::attack(const std::string &target)
{
	if (_hp > 0 && _ep > 0 && _ep--)
	{
		std::cout << "ScavTrap " << _name << " attacks " 
		<< target << ", causing " << _at << " points of damage\n(" 
		<< _name << " now has " << _ep << " energy points left)\n";
	}
	else if (_hp == 0)
	{
		std::cout << "Cannot attack, ScavTrap " << _name 
		<< " is out of hit points\n";
	}
	else
		std::cout << "Cannot attack, ScavTrap " << _name 
		<< " is out of energy points\n";
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name 
    << "is now in Gate keeper mode" << std::endl;
}