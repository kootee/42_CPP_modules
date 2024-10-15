/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:27:36 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/15 15:43:31 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie () : _name("") {}

Zombie::Zombie (std::string str) : _name(str) {}

Zombie::~Zombie () { std::cout << this->_name << DESTROY << std::endl; }

void	Zombie::announce(void)
{
	std::cout << this->_name << BRAINS << std::endl;
}