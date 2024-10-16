/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:50:12 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 12:05:13 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "incorrect amount of arguments" << std::endl;
        return (1);
    }
    else
    {
        Sed sed_inst(argv[1], argv[2], argv[3]);
        if (sed_inst.run_sed() == 0)
        {
            std::cout << "successfully created " << argv[1] 
            << ".replace" << std::endl;
        }
    }
}