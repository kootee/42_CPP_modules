/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:16:27 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:15:53 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.cpp"
// # include "ScavTrap.cpp"

#include <iostream>

class FragTrap: public ClapTrap
{
	public:
			FragTrap(std::string);
			~FragTrap();

			// Member functions
			void	highFivesGuys(void);
};