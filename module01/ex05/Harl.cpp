/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:19:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/08 16:51:12 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::complain(std::string level)
{
    int complaint_level = std::stoi(level);

    void    (Harl::*complaints[4])();
    
    complaints[0] = &Harl::debug;
    complaints[1] = &Harl::info;
    complaints[2] = &Harl::warning;
    complaints[3] = &Harl::error;
    
    (this->*(complaints[complaint_level]))();
}

void    Harl::debug(void)
{
    std::cout << DEBUG << std::endl;
}

void    Harl::info(void)
{
    std::cout << INFO << std::endl;
}

void    Harl::warning(void)
{
    std::cout << WARNING << std::endl;
}

void    Harl::error(void)
{
    std::cout << ERROR << std::endl;
}