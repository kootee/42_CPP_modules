/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:12 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:10:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    if (N = 0)
        return (nullptr);
    Zombie  *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].init_zombie(name);
    return (horde);
}