/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:48 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

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
			ClapTrap &operator= (const ClapTrap &); // Copy assignment operator
			~ClapTrap(); 					// Destructor

			// Class member functions
			void	attack(const std::string &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
};

#endif