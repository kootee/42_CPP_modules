/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:33:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:40:52 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : DiamondTrap(name), ClapTrap(name)
{
    
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My ClapTrap name is " << this->_name;
}