/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:59:16 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 08:00:15 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

# include <iostream>
# include <std::string>
# include <cctype>

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

using namespace std;

int main(int argc, char **argv)
{
    std::string arg;
    
    if (argc == 1)
    {
        std::cout << DEFAULT_MSG << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        arg = argv[i];

        for (std::string::iterator i = arg.begin(); i != arg.end(); ++i)
            *i = toupper(*i);
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return (0);
}
