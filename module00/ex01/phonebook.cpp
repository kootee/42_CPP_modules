/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/04 14:44:22 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int exit_phonebook(int exit_value)
{
    if (exit_value)
        cout << EXIT_MSG << endl;
    return (0);
}

int check_search_id(const string& str)
{
    string::const_iterator c = str.begin();
    while (c != str.end())
    {
        if (!isdigit(*c))
            return (1);
        c++;   
    }
    return (0);
}

int PhoneBook:: index = 0, status = 0;

void	PhoneBook::add_contact()
{
	string a, b, c, d, e;

	if ((cout << FIRST_NAME) && !(cin >> a))
        return ;
	if ((cout << LAST_NAME) && !(cin >> b))
        return ;
	if ((cout << NICKNAME) && !(cin >> c))
        return ;
	if ((cout << PHONE_NUMBER) && !(cin >> d))
        return ;
	if ((cout << DARKEST_SECRET) && !(cin >> e))
        return ;
	contacts[index % 8] = Contact (a, b, c, d, e);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	index++;
}

void	PhoneBook::search_contact()
{
	string		input;
	long int	id_print;

    cout << endl << PHONEBOOK_HEADER << endl << COLUMNS << endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_column(i);
	while (true)
	{
		cout << SEARCH_PROMPT;
		if (!getline(cin, input))
        {
            status = 1;
            return ;
        }
        if (input == "BACK")
            return ;
        else if (!check_search_id(input))
		    id_print = atoi(input.c_str());
		if ((id_print > 7 || id_print < 0) 
            || (!index || id_print > index % 8))
			cout << INVALID_SEARCH_ID << endl;
		else
		{
			contacts[id_print].print_contact_info();
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