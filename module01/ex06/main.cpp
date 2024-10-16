/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:18:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 12:26:27 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl complainer_harl;
    
    // Existing
    std::cout << "***** Complaining from level DEBUG *****" << std::endl;
    complainer_harl.complain("DEBUG");
    std::cout << "***** Complaining from level INFO *****" << std::endl;
    complainer_harl.complain("INFO");
    std::cout << "***** Complaining from level WARNING *****" << std::endl;
    complainer_harl.complain("WARNING");
    std::cout << "***** Complaining from level ERROR *****" << std::endl;
    complainer_harl.complain("ERROR");
    // Nonexisting
    std::cout << "*****Testing some nonexistent ones *****" << std::endl;
    complainer_harl.complain("NONEXISTENT");
    complainer_harl.complain("123");
    complainer_harl.complain("");
    
    return (0);
}