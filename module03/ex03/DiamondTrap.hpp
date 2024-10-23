/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:26:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:53 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
            std::string _name;
    public:
            DiamondTrap();
            DiamondTrap(std::string);
            DiamondTrap(const DiamondTrap&);
            
            
            DiamondTrap& operator=(const DiamondTrap&);
            
            // Class member functions
            void    attack(const std::string);
            void    whoAmI();
};