/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/24 14:56:20 by ktoivola         ###   ########.fr       */
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
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " 
		<< target << ", causing " << _at << " points of damage" 
		<< std::endl;
		_ep--;
	}
	else if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of hit points" 
		<< std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is out of energy points" 
		<< std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hp)
	{
		std::cout << "ClapTrap " << _name << " took " << _hp 
		<< " points of damage" << std::endl;
		_hp = 0;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " took " << amount 
		<< " points of damage" << std::endl;
		_hp -= amount;
	}
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0 && _hp > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "ClapTrap " << _name << "repaired itself for " 
		<< amount << " points" << std::endl;
	}
	else if (_hp == 0)
		std::cout << "ClapTrap " << _name << "is out of hit points" 
		<< std::endl;
	else
		std::cout << "ClapTrap " << _name << "is out of energy points" 
		<< std::endl;
}