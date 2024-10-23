/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 18:33:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap 
{
	private:
			std::string		_name;
			unsigned int	_hp; // Hit points
			unsigned int	_ep; // Energy points
			unsigned int	_at; // Attack damage
	public:
			ClapTrap(); 					// Default constructor
			ClapTrap(std::string); 			// Parameterized constructor
			ClapTrap(const ClapTrap &); 	// Copy constructor
			~ClapTrap(); 					// Destructor

			ClapTrap &operator= (const ClapTrap &); // Copy assignment operator overload
			
			// Class member functions
			void	attack(const std::string &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
};