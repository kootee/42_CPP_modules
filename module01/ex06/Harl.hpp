/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:18:43 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 12:16:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG "DEBUG: Back in my day, things were built to last!"
# define INFO "INFO: Kids these days, always staring at those screens."
# define WARNING "WARNING: Why's everything so expensive now? I remember when a loaf of bread cost just a nickel!"
# define ERROR "ERROR: All this noise! They don't make music like they used to. Now it's just noise and yelling."
# define INVALID_LEVEL "Invalid complaint level."

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
public:
    Harl        (); // Default constructor
    
    std::string levels[4];
    void        complain(std::string);
    void        (Harl::*complaints[4])();
};

#endif