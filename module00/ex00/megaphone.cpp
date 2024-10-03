/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:59:16 by ktoivola          #+#    #+#             */
/*   Updated: 2024/09/23 16:42:25 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

# include <iostream>
# include <string>
# include <cctype>

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

using namespace std;

int main(int argc, char **argv)
{
    string arg;
    
    if (argc == 1)
    {
        cout << DEFAULT_MSG << endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        arg = argv[i];

        for (string::iterator i = arg.begin(); i != arg.end(); ++i)
            *i = toupper(*i);
        cout << arg << " ";
    }
    cout << endl;
    return (0);
}
