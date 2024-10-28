/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:26:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 11:08:15 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define DT_DEFAULT_CONST	"DiamondTrap default constructor called"
#define DT_PARAM_CONST		" was created by DiamondTrap constructor"
#define DT_COPY_CONST		" was created by the DiamondTrap copy constructor"
#define DT_COPY_ASSIGN		" was created by the DiamondTrap copy assignment operator"
#define DT_DESTRUCTOR		" was destroyed by the DiamondTrap destructor"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
			std::string _name;
	public:
			DiamondTrap();
			DiamondTrap(std::string);
			DiamondTrap(const DiamondTrap&);
			~DiamondTrap();
			
			DiamondTrap& operator=(const DiamondTrap&);
			
			// Class member functions
			void    attack(const std::string &target);
			void    whoAmI();
};