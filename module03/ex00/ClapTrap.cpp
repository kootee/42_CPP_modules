/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 18:38:25 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors - Assignment operator - Destructor */
ClapTrap::ClapTrap () : _name(""), _hp(10), _ep(10), _at(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap (std::string name) : _name(name), _hp(10), _ep(10), _at(0)
{
	std::cout << name << " was created by constructor" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &obj)
{
	_name = obj._name;
	_hp = obj._hp;
	_ep = obj._ep;
	_at = obj._at;
	
	std::cout << obj._name << " was created by the copy constructor" 
	<< std::endl;
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
	std::cout << "A copy of " << obj._name 
	<< " was created by the copy assignment operator" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap () 
{
	std::cout << _name << " was destroyed by the destructor" << std::endl;
}

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
	if (_ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "ClapTrap " << _name << "repaired itself for" 
		<< amount << " points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << "is out of energy points" 
		<< std::endl;
}