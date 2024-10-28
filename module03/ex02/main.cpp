/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 10:53:10 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    
    std::cout << "--- Begin tests... creating some Traps ---" << std::endl;
   {
        // Create ClapTrap instances with nicer names
        ClapTrap warrior("Warrior");
        ClapTrap knight("Knight");
        
        FragTrap rogue("Rogue");
        FragTrap healer("Healer");

        FragTrap default1();
        
        std::cout << "\n--- Testing class functions ---" << std::endl;

        // Initial attacks and damage
        warrior.attack("Knight");
        knight.takeDamage(10);
        knight.attack("");
        std::cout << std::endl;

        rogue.highFivesGuys();
        healer.highFivesGuys();
        
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
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
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

        // Check over-healing scenario
        healer.attack("Knight");
        knight.takeDamage(30);
        knight.beRepaired(200);
        warrior.attack("Knight");
        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    {
       // Testing copy assignment operator
        std::cout << "\n--- More tests ---" << std::endl;
        
        ClapTrap mage("Mage_copy"); 
        FragTrap rogue("Rogue Jr");
        FragTrap healer("Healer Jr");

        std::cout << "\n--- Creating copies ---" << std::endl;
        
        ClapTrap mage_copy(mage);
        ClapTrap mage_copy2 = mage_copy;
        
        FragTrap bard("Bard");  
        FragTrap bard_copy = bard;
        FragTrap bard_copy2(bard_copy);
        
        FragTrap wizard ("Wizard");
        FragTrap wizard_copy(wizard);
        
        std::cout << "\n--- Testing class functions ---" << std::endl;

        mage_copy2.attack("Rogue Jr");
        rogue.takeDamage(10);
        std::cout << std::endl;
        mage.attack("Healer");
        healer.takeDamage(15);
        std::cout << std::endl;

        // Further attacks and healing after copying
        mage.beRepaired(25);
        bard_copy.beRepaired(10);
        std::cout << std::endl;

        // Testing copy constructor
        bard.attack("Healer");
        healer.takeDamage(15);
        std::cout << std::endl;

        // Further attacks and healing after copying
        bard.beRepaired(25); 
        rogue.beRepaired(10);

        bard.highFivesGuys();
        bard_copy.highFivesGuys();
        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
   
}