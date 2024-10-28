/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 12:23:07 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "--- Begin tests... creating some DiamondTraps ---" << std::endl;
   {
        // Create ClapTrap instances with nicer names
        DiamondTrap default1;
        default1.whoAmI();
        std::cout << std::endl;
        
        DiamondTrap warrior("Warrior");
        std::cout << std::endl;

        DiamondTrap knight("Knight");
        std::cout << std::endl;
        
        DiamondTrap rogue("Rogue");
        std::cout << std::endl;

        DiamondTrap healer("Healer");
        std::cout << std::endl;

        warrior.whoAmI();
        knight.whoAmI();
        rogue.whoAmI();
        healer.whoAmI();
        
        std::cout << "\n--- Testing class functions ---" << std::endl;
        
        // Initial attacks and damage
        warrior.attack("Knight");
        knight.takeDamage(10);
        knight.attack("Healer");
        std::cout << std::endl;

        rogue.highFivesGuys();
        healer.highFivesGuys();
        std::cout << std::endl;

        rogue.guardGate();
        healer.guardGate();
        std::cout << std::endl;
        
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        std::cout << std::endl;

        healer.takeDamage(2);
        healer.beRepaired(20);
        healer.attack("Rogue");
        std::cout << std::endl;

        rogue.takeDamage(12);
        std::cout << std::endl;
        
        // Testing repeated attacks and damage
        warrior.attack("Rogue");
        rogue.takeDamage(10);
        warrior.attack("Knight");
        knight.takeDamage(8);
        knight.beRepaired(50);  // Knight repairs itself
        std::cout << std::endl;

        // Test for excessive damage (test if ClapTrap can "die" or go to 0 HP)
        rogue.attack("Warrior");
        warrior.takeDamage(100);  // Test if this puts Warrior to 0 HP
        std::cout << std::endl;

        std::cout << "\n--- Creating copies ---" << std::endl;
        
        DiamondTrap warrior_copy(warrior);
        std::cout << std::endl;

        DiamondTrap knight_copy = knight;
        std::cout << std::endl;
        
        warrior.whoAmI();
        knight.whoAmI();
        rogue.whoAmI();
        healer.whoAmI();
        std::cout << std::endl;

        ClapTrap * clap = new DiamondTrap;
        clap->attack("Random");
        clap->beRepaired(10);
        delete clap;
        std::cout << std::endl;

        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }  
}