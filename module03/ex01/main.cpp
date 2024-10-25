/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/25 10:30:35 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- Begin tests... creating some Traps ---" << std::endl;
   {
        // Create ClapTrap instances with nicer names
        ClapTrap warrior("Warrior");
        ClapTrap knight("Knight");
        
        ScavTrap rogue("Rogue");
        ScavTrap healer("Healer");
        
        std::cout << "\n--- Testing class functions ---" << std::endl;

        // Initial attacks and damage
        warrior.attack("Knight");
        knight.takeDamage(10); // Knight dies
        knight.attack("");
        
        std::cout << "\n------" << std::endl;

        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        healer.takeDamage(2);
        healer.beRepaired(20);
        healer.attack("Rogue");
        rogue.takeDamage(12);
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        rogue.attack("Healer");
        
        std::cout << "\n------" << std::endl;
        
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
        knight.takeDamage(30);
        knight.beRepaired(200);

        // Test if a dead ClapTrap can still attack (you may want to add conditions in the class for this)
        warrior.attack("Knight");
        
        std::cout << "\n--- Testing ScavTrap Guard gate ---" << std::endl;
        rogue.guardGate();
        healer.guardGate();
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    {
        // Testing copy assignment operator
        std::cout << "\n--- Testing Copy Assignment ---" << std::endl;
        
        ClapTrap knight("Knight Jr");
        ClapTrap archer("Archer");  
        
        ScavTrap rogue("Rogue Jr");
        ScavTrap healer("Healer Jr");

        archer = knight;            
        archer.attack("Rogue Jr");
        rogue.takeDamage(10);

        // Testing copy constructor
        std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
        
        ClapTrap mage(knight);
        mage.attack("Healer");
        healer.takeDamage(15);

        // Further attacks and healing after copying
        mage.beRepaired(25);
        archer.beRepaired(10);

        // Testing copy assignment operator
        ScavTrap bard("Bard");  
        ScavTrap assasin("Assasin");
        
        bard = assasin;       // testing AcavTrap copy assign
        
        bard.attack("Rogue");
        rogue.takeDamage(10);

        // Testing copy constructor
        ScavTrap wizard = ScavTrap("Wizard");
        bard.attack("Healer");
        healer.takeDamage(15);
        
        ScavTrap wizardjr(wizard); // creating a copy of ScavTrap

        // Further attacks and healing after copying
        bard.beRepaired(25); 
        bard.beRepaired(10);

        std::cout << "\n--- End of scope ---" << std::endl;
    }
    
    return (0);
}