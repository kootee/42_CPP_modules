/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 15:12:49 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors */
ClapTrap::ClapTrap () : _name(""), _hp(10), _ep(10), _at(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap (std::string name) : _name(name), _hp(10), _ep(10), _at(0)
{
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = obj._name;
	_hp = obj._hp;
	_ep = obj._ep;
	_at = obj._at;	
}

ClapTrap& ClapTrap::operator= (const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_at = obj._at;
	}
	return (*this);
}

ClapTrap::~ClapTrap () 
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

/* Class member functions */
void    ClapTrap::attack(const std::string &target)
{
	if (_ep > 0)
	{
		_ep--;
		std::cout << "ClapTrap " << _name << "attacks" << target
		<< ", causing" << _at << " points of damage" 
		<< std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << "is out of energy points" 
		<< std::endl;
	}
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	std::cout << "ClapTrap " << _name << "took" << amount << " points of damage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "ClapTrap " << _name << "repaired itself for" << amount << " points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << "is out of energy points" << std::endl;
}