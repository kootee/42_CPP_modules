/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:25 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 18:38:05 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ct1("1");
    ClapTrap ct2("2");
    ClapTrap ct3("3");
    ClapTrap ct4("4");

    ct1.attack("2");
    ct2.takeDamage(10);
    ct2.attack("1");
    ct1.takeDamage(10);
    ct1.attack("3");
    ct3.takeDamage(10);
    ct1.attack("4");
    ct4.takeDamage(10);
    ct1.attack("3");
    ct3.takeDamage(10);
    ct1.attack("2");
    ct2.takeDamage(10);
    ct2.beRepaired(100000);
    
    return (0);
}