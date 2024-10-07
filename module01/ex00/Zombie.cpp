/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:27:36 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 13:51:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Zombie constructor */
Zombie::Zombie (std::string str) : name(str) {}

/* Zombie default constructor */
Zombie::Zombie () : name("") {}

/* Announce function */
void	Zombie::announce(void)
{
	std::cout << this->name << BRAINS << std::endl;
}