/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/03 11:57:41 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class	Contact 
{
	string  first_name, last_name, nickname;
	string	phone_number;
	string  darkest_secret;

public:
	static int	index;
	void		print_info();
	Contact 	(string a, string b, string c, string d, string e);
};

int Contact:: index = 0;

/* New contact constructor */
Contact::Contact (string a, string b, string c, string d, string e)
{
	first_name = a;
	last_name = b;
	nickname = c;
	phone_number = d;
	darkest_secret = e;
	index++;
}

class	PhoneBook
{
	Contact	*contacts[8];

public:
	void    add_contact(); 
	void	search_contact();
};

void	PhoneBook::add_contact()
{
	string a, b, c, d, e;

	cout << "First name: ";
	cin >> a;
	cout << endl;
	cout << "Last name: ";
	cin >> b;
	cout << endl;
	cout << "Nickname: ";
	cin >> c;
	cout << endl;
	cout << "Phone number: ";
	cin >> d;
	cout << endl;
	cout << "Deepest darkest secret: ";
	cin >> e;
	cout << endl;
	
	contacts[Contact::index] = new Contact (a, b, c, d, e);
}

void	print_too_long(string str)
{ 
	printf("%.*s", 9, str);
	cout << ".|" << endl;
}

void	print_value(string str)
{
	size_t	len;

	len = 10 - str.size();
	if (len < 0)
		print_too_long(str);
	else
	{
		while (len--)
			cout << " ";
		cout << str << "|";
		printf("%s|", str);
	}
}

void	Contact::print_info()
{
	cout << COLUMNS << endl;
	cout << "|" << index;
	print_value(first_name);
	print_value(last_name);
	print_value(nickname);
	cout << "|" << endl;
}

void	PhoneBook::search_contact()
{
	string	to_print;
	int		i = 0;


	while (i++ < 8)
	{
		contacts[i]->print_info();
		cout << "";
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
		{
			if (Contact::index == 7)
				Contact::index = 0;
			phonebook.add_contact();
		}
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}