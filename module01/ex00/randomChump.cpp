/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:07:13 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 14:00:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  It creates a zombie, name it, and the zombie announces itself. */
void    randomChump(std::string name)
{
    Zombie randomchump = name;
    randomchump.announce();
}