/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 17:53:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
    ClapTrap new_inst = name;
    _hp = 100;
    _ep = 100;
    _at = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Let's high five!!!" << std::endl;
}

/* Member functions */
void    FragTrap::attack(const std::string &target)
{
    ClapTrap::attack(target);
    
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