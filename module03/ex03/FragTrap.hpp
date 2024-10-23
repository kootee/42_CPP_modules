/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:16:27 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 18:55:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.cpp"
// # include "ScavTrap.cpp"

#include <iostream>

class FragTrap: virtual public ClapTrap
{
	public:
			FragTrap(std::string);
			~FragTrap();

			// Member functions
			void	highFivesGuys(void);
};