/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:11:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/04 15:01:06 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int horde_size = 8;

	Zombie *testhorde = zombieHorde(horde_size, "tyyne");

	for (int i = 0; i < horde_size; i++)
	{
		testhorde[i].announce();
	}
	delete[] testhorde;
}