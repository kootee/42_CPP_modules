/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/06 16:07:53 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int exit_phonebook(int exit_value)
{
    if (exit_value)
        cout << EXIT_MSG << endl;
    return (0);
}

int check_search_id(const string& str, int phonebook_id)
{
    int id;

    string::const_iterator c = str.begin();
    while (c != str.end())
    {
        if (!isdigit(*c))
        {
            cout << INVALID_INPUT << endl;
            return (-1);
        }
        c++;   
    }
    id = atoi(str.c_str());
	if ((id > 7 || id < 0) 
        || (phonebook_id == 0 || id > (phonebook_id - 1) % 8))
        {
		    cout << OUT_OF_RANGE_ID << endl;
            return (-1);
        }
    return (id);
}

int PhoneBook:: index = 0, status = 0;

void	PhoneBook::add_contact()
{
	string name, lastname, nickname, number, secret;

    if ((cout << FIRST_NAME) &&!getline(cin, name))
        return ;
    if ((cout << LAST_NAME) && !getline(cin, lastname))
        return ;
    if ((cout << NICKNAME) && !getline(cin, nickname))
        return ;
    if ((cout << PHONE_NUMBER) && !getline(cin, number))
        return ;
    if ((cout << DARKEST_SECRET) && !getline(cin, secret))
        return ;
	contacts[index % 8] = Contact (name, lastname, nickname, number, secret);
	index++;
}

void	PhoneBook::search_contact()
{
	string		input;
	long int	id_print;

    id_print = -1;
    cout << endl << PHONEBOOK_HEADER << endl << COLUMNS << endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_column(i);
	while (true)
	{
		cout << SEARCH_PROMPT;
		if (!getline(cin, input))
            return ;
        if (input == "BACK")
            return ;
        id_print = check_search_id(input, this->index);
        if (id_print != -1)
		{
			contacts[id_print].print_contact_info(id_print);
			return ;
		}
	}
}

int	main()
{
	PhoneBook   phonebook;
	string      input;

	while (true)
	{
        if (cin.eof())
            return (exit_phonebook(1));
		cout << PROMPT;
		if (!getline(cin, input))
            return (exit_phonebook(1));
		if (input == "EXIT")
			return (exit_phonebook(0));
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}