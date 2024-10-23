/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:07 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 17:43:56 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.cpp"
#include <iostream>

/* Derived class from ClapTrap class */
class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(std::string);
        ~ScavTrap();
        ScavTrap(const ScavTrap&); // Copy constructor
        
        ScavTrap& operator=(const ScavTrap&);
    
    // Member functions
    void    attack(const std::string &);
    void    guardGate();
};

