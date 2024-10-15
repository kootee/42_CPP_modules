/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:27:31 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:07 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/* Constructor test */
	std::cout << "*************Constructor test*************" << std::endl;
	Zombie zombie1("Buttercup");
	Zombie zombie2("Bubbles");
	Zombie zombie3("Peanutbutter");
	zombie1.announce();
	zombie2.announce();
	zombie3.announce();

	/* RandomChump test */
	std::cout << "*************RandomChump test*************" << std::endl;
	randomChump("Jim");
	randomChump("Luigi");
	randomChump("Mario");

	/* NewZombie test */
	std::cout << "*************NewZombie test*************" << std::endl;
	Zombie *z1 = newZombie("1");
	Zombie *z2 = newZombie("2");
	Zombie *z3 = newZombie("3");
	Zombie *z4 = newZombie("4");
	z1->announce();
	z2->announce();
	z3->announce();
	z4->announce();
	
	/* Delete allocated zombies */
	delete(z1);
	delete(z2);
	delete(z3);
	delete(z4);
	std::cout << "*************exiting main*************" << std::endl;
}