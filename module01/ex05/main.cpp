/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:18:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/09 14:04:27 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl complainer_harl;
    
    complainer_harl.complain("DEBUG");
    complainer_harl.complain("INFO");
    complainer_harl.complain("WARNING");
    complainer_harl.complain("ERROR");
    complainer_harl.complain("NONEXISTENT");
    complainer_harl.complain("123");
    complainer_harl.complain("");
    
    return (0);
}