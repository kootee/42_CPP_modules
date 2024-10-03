/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/09/23 16:43:31 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class Contact 
{
    string  first_name;
    string  last_name;
    string  nickname;
    int     phone_number;
    string  darkest_secret;
};

class PhoneBook
{
    Contact person;
    void    add_contact(string, string, string, int, string); 
};

void    PhoneBook::add_contact(string a, string b, string c, int nbr, string d)
{
    
}

int main()
{
    PhoneBook   phonebook;
    string      input;
    bool        run;

    run = true;
    while (run)
    {
        getline(cin, input);
        if (input == "EXIT")
            run = false;
        else if (input == "ADD")
        {
            // add
            phonebook.add_contact();
        }
        else if (input == "SEARCH")
        {
            // search
        }
    }
    // free phonebook?
    return (0);
}