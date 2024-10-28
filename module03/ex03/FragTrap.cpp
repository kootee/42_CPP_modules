/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:05 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 14:50:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap()
{
    _hp = 100;
    _ep = 100;
    _at = 30;
    std::cout << FT_DEFAULT_CONST << std::endl;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 100;
    _at = 30;
    std::cout << _name << FT_PARAM_CONST << std::endl;
}

FragTrap::FragTrap (const FragTrap &obj) : ClapTrap(obj)
{
	_name = obj._name;
	_hp = obj._hp;
	_ep = obj._ep;
	_at = obj._at;
	std::cout << obj._name <<  FT_COPY_CONST << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << _name << FT_DESTRUCTOR << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_at = obj._at;
	}
	std::cout << obj._name << FT_COPY_ASSIGN << std::endl;
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "I'm " << _name << ", let's high five!!!\n";
}