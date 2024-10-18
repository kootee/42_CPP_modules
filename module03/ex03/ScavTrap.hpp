/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:07 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 14:49:02 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.cpp"

/* Derived class from ClapTrap class */
class ScavTrap: public ClapTrap
{
public:
    ScavTrap(std::string);
    ~ScavTrap();
    
    // Member functions
    void    attack(std::string &);
    void    guardGate();
};

