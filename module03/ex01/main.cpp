/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 14:27:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- Begin tests... creating some Traps ---" << std::endl;
   {
        // Create ClapTrap instances with nicer names
        ScavTrap rogue("Rogue");
        ScavTrap healer("Healer");
        
        std::cout << "\n--- Testing class functions ---" << std::endl;
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
        rogue.attack("Warrior");
        std::cout << std::endl;

        std::cout << "\n--- Testing ScavTrap Guard gate ---" << std::endl;
        rogue.guardGate();
        healer.guardGate();
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    {
        std::cout << "\n--- More tests ---" << std::endl;
        
        ScavTrap rogue("Rogue Jr");
        ScavTrap healer("Healer Jr");

        std::cout << "\n--- Creating copies ---" << std::endl;
        
        ScavTrap bard("Bard");  
        ScavTrap bard_copy = bard;
        ScavTrap bard_copy2(bard_copy);
        
        ScavTrap wizard ("Wizard");
        ScavTrap wizard_copy(wizard);
        
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
        
        std::cout << "\n--- End of scope... destroying traps ---" << std::endl;
    }
    
    return (0);
}