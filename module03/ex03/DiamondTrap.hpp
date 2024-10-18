/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:26:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:46:47 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
            std::string _name;
            ClapTrap::  _name;
            FragTrap::_hp;
            ScavTrap::_ep;
            FragTrap::_at;
            ScavTrap::attack;
    public:
            DiamondTrap(std::string name):  {};
            
            // Class member functions
            void    whoAmI();
};