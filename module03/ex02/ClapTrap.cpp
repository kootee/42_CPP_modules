/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 09:25:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors - Assignment operator - Destructor */
ClapTrap::ClapTrap () : _name("Default"), _hp(10), _ep(10), _at(0)
{
	std::cout << DEFAULT_CONST << std::endl;
}

ClapTrap::ClapTrap (std::string name) : _name(name), _hp(10), _ep(10), _at(0)
{
	std::cout << name << PARAM_CONST << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &obj)
{
	_name = obj._name;
	_hp = obj._hp;
	_ep = obj._ep;
	_at = obj._at;
	std::cout << obj._name <<  COPY_CONST << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_at = obj._at;
	}
	std::cout << obj._name << COPY_ASSIGN << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap () { std::cout << _name << DESTRUCTOR << std::endl; }

/* Class member functions */
void    ClapTrap::attack(const std::string &target)
{
	if (_hp > 0 && _ep > 0 && _ep--)
	{
		std::cout << "ClapTrap " << _name << " attacks " 
		<< target << ", causing " << _at << " points of damage\n(" 
		<< _name << " now has " << _ep << " energy points left)\n";
	}
	else if (_hp == 0)
	{
		std::cout << "Cannot attack, ClapTrap " << _name 
		<< " is out of hit points\n";
	}
	else
		std::cout << "Cannot attack, ClapTrap " << _name 
		<< " is out of energy points\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hp)
	{
		std::cout << "ClapTrap " << _name << " took " << _hp 
		<< " points of damage\n(" << _name << " is out of hit points)\n";
		_hp = 0;
	}
	else
	{
		_hp -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount 
		<< " points of damage\n(" << _name << " now has " 
		<< _hp << " hit points left)\n";
	}
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp > 0 && _ep > 0 && _ep--)
	{
		_hp += amount;
		std::cout << "ClapTrap " << _name << " repaired itself for " 
		<< amount << " points\n(" << _name << " now has " 
		<< _hp << " hit points left)\n";
	}
	else if (_hp == 0)
		std::cout << "Cannot repair, ClapTrap " << _name 
		<< "is out of hit points\n";
	else
		std::cout << "Cannot repair, ClapTrap " << _name 
		<< "is out of energy points\n";
}