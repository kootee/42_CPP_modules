/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/24 14:47:36 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    // Create ClapTrap instances with nicer names
    ClapTrap warrior("Warrior");
    ClapTrap knight("Knight");
    ClapTrap rogue("Rogue");
    ClapTrap healer("Healer");

    // Initial attacks and damage
    warrior.attack("Knight");
    knight.takeDamage(10);
    knight.attack("Warrior");
    warrior.takeDamage(10);

    rogue.attack("Healer");
    healer.takeDamage(15);  // Testing a different damage value
    healer.beRepaired(20);  // Healer repairs itself
    healer.attack("Rogue");
    rogue.takeDamage(12);

    // Testing repeated attacks and damage
    warrior.attack("Rogue");
    rogue.takeDamage(10);
    warrior.attack("Knight");
    knight.takeDamage(8);
    knight.beRepaired(50);  // Knight repairs itself

    // Test for excessive damage (test if ClapTrap can "die" or go to 0 HP)
    rogue.attack("Warrior");
    warrior.takeDamage(100);  // Test if this puts Warrior to 0 HP

    // Check over-healing scenario
    healer.attack("Knight");
    knight.takeDamage(30);     // Knight takes some more damage
    knight.beRepaired(200);    // Knight tries to heal a huge amount (check max HP behavior)

    // Test if a dead ClapTrap can still attack (you may want to add conditions in the class for this)
    warrior.attack("Knight");
    
// Testing copy assignment operator
    std::cout << "\n--- Testing Copy Assignment ---" << std::endl;
    ClapTrap archer("Archer");  // New ClapTrap "Archer"
    archer = knight;            // Assign "Knight" to "Archer" (testing copy assignment overload)
    archer.attack("Rogue");     // Test if "Archer" behaves like "Knight" after assignment
    rogue.takeDamage(10);

    // Testing copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap mage(knight);      // Create "Mage" as a copy of "Knight" (testing copy constructor)
    mage.attack("Healer");      // Test if "Mage" behaves like "Knight"
    healer.takeDamage(15);

    // Further attacks and healing after copying
    mage.beRepaired(25);        // "Mage" repairs itself
    archer.beRepaired(10);      // "Archer" repairs itself

    return (0);
}