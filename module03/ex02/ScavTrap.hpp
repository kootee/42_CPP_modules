/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:07 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 09:52:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

#define ST_DEFAULT_CONST    "ScavTrap default constructor called"
#define ST_PARAM_CONST		" was created by ScavTrap constructor"
#define ST_COPY_CONST		" was copied by the ScavTrap copy constructor"
#define ST_COPY_ASSIGN		" was copied by the ScavTrap copy assignment operator"
#define ST_DESTRUCTOR		" was destroyed by the ScavTrap destructor"

/* Derived class from ClapTrap class */
class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&); // Copy constructor
        ~ScavTrap();
        
        ScavTrap& operator=(const ScavTrap&);
    
        // Member functions
        void    attack(const std::string &);
        void    guardGate();
};

