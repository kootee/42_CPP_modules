/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:01:26 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 17:37:46 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon  club = Weapon("crude spiked club");
    
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("baseball bat");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spike club");
        
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("tennis racket");
        jim.attack();
    }
    {
        Weapon club = Weapon("crude spike club");
        
        HumanB jim("Jim");
        jim.attack();
        club.setType("tennis racket");
        jim.setWeapon(club);
        jim.attack();
    }
    return (0);
}