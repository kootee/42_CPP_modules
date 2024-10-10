
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:19:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/09 15:05:27 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    complaints[0] = &Harl::debug;
    complaints[1] = &Harl::info;
    complaints[2] = &Harl::warning;
    complaints[3] = &Harl::error;
}

int get_complaint_lvl(std::string level, Harl current_harl)
{
    int lvl = 0;
    
    while (lvl < 4)
    {
        if (current_harl.levels[lvl] == level)
            return (lvl);
        lvl++;
    }
    return (-1);
}

void    Harl::complain(std::string level)
{
    int complaint_level = get_complaint_lvl(level, *this);
    
    if (complaint_level < 0)
    {
        std::cout << INVALID_LEVEL << std::endl;
        return ;
    }
    switch (complaint_level)
    {
        case 0:
            (this->*(complaints[0]))();
        case 1:
            (this->*(complaints[1]))();
        case 2:
            (this->*(complaints[2]))();
        case 3:
            (this->*(complaints[3]))();
    }
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