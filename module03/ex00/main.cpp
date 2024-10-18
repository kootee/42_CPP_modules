/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/18 12:26:12 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.cpp"

int main(void)
{
    ClapTrap ct1("ClapTrap1");
    ClapTrap ct2("ClapTrap2");
    ClapTrap ct3("ClapTrap3");
    ClapTrap ct4("ClapTrap4");

    ct1.attack("ct2");
    ct2.takeDamage(10);
    ct2.attack("ct1");
    ct1.attack("random");
    ct1.attack("ct5");
    ct1.attack("ct754");
    ct1.attack("ctgreg");
    ct2.beRepaired(100000);
    
    return (0);
}