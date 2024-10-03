/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/03 10:56:41 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class	Contact 
{
	string  first_name, last_name, nickname;
	string	phone_number;
	string  darkest_secret;

public:
	Contact (string a, string b, string c, string d, string e);
	int		index;
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
	int		num = 0;
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
	
	contacts[num] = new Contact (a, b, c, d, e);
	contacts[num]->index = num;
	num++;
}

void	PhoneBook::search_contact()
{
	string	name;
	
	cout << "Search for:";
	cin >> name;
}

int	main()
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
			if (phonebook.num == 7)
				phonebook.num = 0;
			phonebook.add_contact();
		}
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}