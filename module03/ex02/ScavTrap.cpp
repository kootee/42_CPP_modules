/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 15:12:41 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 50;
    _at = 20;
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

/* Member functions */
void    ScavTrap::attack(std::string &target)
{
	if (_ep > 0)
	{
		_ep--;
		std::cout << "ScavTrap " << _name << "attacks" << target
        << ", causing" << _at << " points of damage" 
        << std::endl;
	}
	else
    {
		std::cout << "ScavTrap " << _name << "is out of energy points" 
        << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << "is now in Gate keeper mode" << std::endl;

}