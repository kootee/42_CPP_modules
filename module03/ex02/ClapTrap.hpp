/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:18:33 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/* Base class ClapTrap */
class ClapTrap {
protected:
		std::string _name;
		int			_hp; // Hit points
		int			_ep; // Energy points
		int			_at; // Attack damage
public:
		ClapTrap(); // Default constructor
		ClapTrap(std::string); // Parameterized constructor
		ClapTrap(const ClapTrap &); // Copy constructor
		ClapTrap &operator= (const ClapTrap &); // Copy assignment operator
		~ClapTrap(); // Destructor

		/* Class member functions */
		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};
