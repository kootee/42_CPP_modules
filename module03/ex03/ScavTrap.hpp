/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:07 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 18:55:28 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.cpp"

/* Derived class from ClapTrap class */
class ScavTrap: virtual public ClapTrap
{
public:
    ScavTrap(std::string);
    ~ScavTrap();
    
    // Member functions
    void    attack(std::string &);
    void    guardGate();
};

