/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:33:11 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 13:56:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  It creates a zombie, name it, and return it so you can use it outside 
    of the function scope */
Zombie  *newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return (zombie);
}