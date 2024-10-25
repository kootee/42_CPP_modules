/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/25 12:44:37 by ktoivola         ###   ########.fr       */
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
        std::cout << std::endl;

        warrior.attack("Knight");
        
        std::cout << "\n--- Testing ScavTrap Guard gate ---" << std::endl;
        rogue.guardGate();
        healer.guardGate();
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    {
        // Testing copy assignment operator
        std::cout << "\n--- More tests ---" << std::endl;
        
        ClapTrap knight("Knight Jr");
        ClapTrap archer("Archer");  
        ScavTrap rogue("Rogue Jr");
        ScavTrap healer("Healer Jr");

        std::cout << "\n--- Creating copies ---" << std::endl;
        ClapTrap mage(knight);
        archer = knight;
        ScavTrap bard("Bard");  
        ScavTrap assasin("Assasin");
        bard = assasin;
        ScavTrap wizard = ScavTrap("Wizard");
        ScavTrap wizard2(ScavTrap("Wizard 2"));
        
        std::cout << "\n--- Testing class functions ---" << std::endl;

        archer.attack("Rogue Jr");
        rogue.takeDamage(10);
        std::cout << std::endl;
        mage.attack("Healer");
        healer.takeDamage(15);
        std::cout << std::endl;

        // Further attacks and healing after copying
        mage.beRepaired(25);
        archer.beRepaired(10);
        std::cout << std::endl;

        // Testing copy constructor
        bard.attack("Healer");
        healer.takeDamage(15);
        std::cout << std::endl;

        // Further attacks and healing after copying
        bard.beRepaired(25); 
        rogue.beRepaired(10);
        
        std::cout << "\n--- End of scope ---" << std::endl;
    }
    
    return (0);
}