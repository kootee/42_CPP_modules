/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 14:18:53 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap default_claptap;
    ClapTrap warrior("Warrior");
    ClapTrap knight("Knight");
    ClapTrap rogue("Rogue");
    ClapTrap healer("Healer");
    std::cout << std::endl;

    default_claptap.attack("Knight");
    warrior.attack("Knight");
    knight.takeDamage(10); 
    knight.attack("Warrior");
    warrior.takeDamage(5);

    rogue.attack("Healer");
    healer.takeDamage(3);
    healer.beRepaired(20);
    healer.attack("Rogue");
    rogue.takeDamage(12);

    std::cout << std::endl;
    warrior.attack("Rogue");
    rogue.takeDamage(10);
    warrior.attack("Knight");
    knight.takeDamage(8);
    knight.beRepaired(50);

    rogue.attack("Warrior");
    warrior.takeDamage(100);

    healer.attack("Knight");
    knight.takeDamage(30);
    knight.beRepaired(200);

    warrior.attack("Knight");
    
    std::cout << "\n--- Testing Copy Assignment ---" << std::endl;
    ClapTrap archer("Archer");
    ClapTrap archer_copy = archer;
    archer_copy.attack("Archer");
    archer.takeDamage(10);

    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap knight_copy(knight);
    knight_copy.attack("Healer");
    healer.takeDamage(15);

    knight_copy.beRepaired(25);
    archer.beRepaired(10);
    std::cout << std::endl;

    return (0);
}