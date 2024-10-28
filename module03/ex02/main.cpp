/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 14:30:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    
    std::cout << "--- Begin tests... creating some Traps ---" << std::endl;
   {
        FragTrap rogue("Rogue");
        FragTrap healer("Healer");
        FragTrap default1;
        
        std::cout << "\n--- Testing class functions ---" << std::endl;
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
        
        rogue.takeDamage(10);
        std::cout << std::endl;

        rogue.attack("Warrior");
        std::cout << std::endl;

        // Check over-healing scenario
        healer.attack("Knight");
        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    {
       // Testing copy assignment operator
        std::cout << "\n--- More tests ---" << std::endl;
         
        FragTrap rogue("Rogue Jr");
        FragTrap healer("Healer Jr");

        std::cout << "\n--- Creating copies ---" << std::endl;

        FragTrap bard("Bard");  
        FragTrap bard_copy = bard;
        FragTrap bard_copy2(bard_copy);
        
        FragTrap wizard ("Wizard");
        FragTrap wizard_copy(wizard);
        
        std::cout << "\n--- Testing class functions ---" << std::endl;

        rogue.takeDamage(10);
        std::cout << std::endl;
        healer.takeDamage(15);
        std::cout << std::endl;

        bard_copy.beRepaired(10);
        std::cout << std::endl;

        bard.attack("Healer");
        healer.takeDamage(15);
        std::cout << std::endl;

        bard.beRepaired(25); 
        rogue.beRepaired(10);

        bard.highFivesGuys();
        bard_copy.highFivesGuys();
        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
   
}