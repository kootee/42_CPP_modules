/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 14:30:58 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 50;
    _at = 20;
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
}

/* Member functions */
void    ScavTrap::attack(std::string &target)
{
    
}