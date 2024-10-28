/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:16:27 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 10:39:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

#define FT_DEFAULT_CONST    "FragTrap default constructor called"
#define FT_PARAM_CONST		" was created by FragTrap constructor"
#define FT_COPY_CONST		" was copied by the FragTrap copy constructor"
#define FT_COPY_ASSIGN		" was copied by the FragTrap copy assignment operator"
#define FT_DESTRUCTOR		" was destroyed by the FragTrap destructor"

class FragTrap: virtual public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string);
			FragTrap(const FragTrap&);
			~FragTrap();
			
			FragTrap&	operator=(const FragTrap&);

			// Member functions
			void	highFivesGuys(void);
};