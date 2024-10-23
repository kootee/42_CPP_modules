/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:16:27 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 17:49:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.cpp"
#include <iostream>

class FragTrap: public ClapTrap
{
	public:
			FragTrap(std::string);
			~FragTrap();
			FragTrap(const FragTrap&);
			
			FragTrap&	operator=(const FragTrap&);

			// Member functions
			void	attack(const std::string&);
			void	highFivesGuys(void);
};