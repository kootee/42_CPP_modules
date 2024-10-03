/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/03 15:58:15 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class	Contact 
{
	string  first_name, last_name, nickname;
	string	phone_number;
	string  darkest_secret;
	
public:
	void		print_column(int idx);
	void		print_contact_info();
	Contact 	(string a, string b, string c, string d, string e);
};


/* New contact constructor */
Contact::Contact (string a, string b, string c, string d, string e)
{
	first_name = a;
	last_name = b;
	nickname = c;
	phone_number = d;
	darkest_secret = e;
}

class	PhoneBook
{
	Contact	*contacts[8];
public:
	static int	index;
	void    add_contact(); 
	void	search_contact();
};

int PhoneBook:: index = 0;

void	PhoneBook::add_contact()
{
	string a, b, c, d, e;

	cout << FIRST_NAME;
	cin >> a;
	cout << LAST_NAME;
	cin >> b;
	cout << NICKNAME;
	cin >> c;
	cout << PHONE_NUMBER;
	cin >> d;
	cout << DARKEST_SECRET;
	cin >> e;
	
	contacts[index % 8] = new Contact (a, b, c, d, e);
	index++;
}
iindex
void	print_value(string str)
{
	size_t	len;

	len = 10 - str.size();
	if (len < 0)
	{
		printf("%.*s", 9, str);
		cout << ".|";
	}
	else
	{
		while (len--)
			cout << " ";
		cout << str << "|";
		printf("%s|", str);
	}
}

void	Contact::print_column(int idx)
{
	cout << COLUMNS << endl;
	cout << "|         " << idx;
	print_value(first_name);
	print_value(last_name);
	print_value(nickname);
	cout << endl;
}

void	Contact::print_contact_info()
{
	cout << FIRST_NAME << first_name << endl;
	cout << LAST_NAME << last_name << endl;
	cout << NICKNAME << nickname << endl;
	cout << PHONE_NUMBER << phone_number << endl;
	cout << DARKEST_SECRET << darkest_secret << endl;
}

void	PhoneBook::search_contact()
{
	char		*input;
	long int	id_print;

	for (int i = 0; i < 8; i++)
		contacts[i]->print_column(i);
	while (true)
	{
		cout << "Enter index to display: ";
		cin >> input;
		id_print = atoi(input);
		if ((id_print > 7 || id_print < 0) || id_print > index % 8)
			cout << INVALID_SEARCH_ID << endl;
		else
		{
			contacts[id_print]->print_contact_info();
			break ;
		}
	}
}

int	main()
{
	PhoneBook   phonebook;
	string      input;

	while (true)
	{
		cout << "Enter phonebook command: " << endl;
		getline(cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}