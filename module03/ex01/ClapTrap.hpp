/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/24 14:55:45 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEFAULT_CONST	"ClapTrap default constructor called"
#define PARAM_CONST		" was created by ClapTrap constructor"
#define COPY_CONST		" was created by the ClapTrap copy constructor"
#define COPY_ASSIGN		" was created by the ClapTrap copy assignment operator"
#define DESTRUCTOR		" was destroyed by the ClapTrap destructor"

class ClapTrap 
{
	protected:
			std::string _name;
			int			_hp; // Hit points
			int			_ep; // Energy points
			int			_at; // Attack damage
	public:
			ClapTrap(); 				// Default constructor
			ClapTrap(std::string); 		// Parameterized constructor
			ClapTrap(const ClapTrap &); // Copy constructor
			~ClapTrap(); 				// Destructor
			
			ClapTrap &operator= (const ClapTrap &); // Copy assignment operator

			// Class member functions
			virtual void	attack(const std::string &target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
};
