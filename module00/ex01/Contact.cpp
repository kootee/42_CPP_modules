/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:48:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/04 18:53:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_value(string str)
{
	size_t	len;

	len = str.size();
	if (len >= 10)
	{
        for (int i = 1; i < 10; i++)
            cout << str[i];
		cout << ".|";
	}
	else
	{
		for (int i = 0; i < (10 - len); i++)
			cout << " ";
		cout << str << "|";
	}
}

/* Contact class parameters constructor */
Contact::Contact (string a, string b, string c, string d, string e)
{
	first_name = a;
	last_name = b;
	nickname = c;
	phone_number = d;
	darkest_secret = e;
}

/* Contact class default constructor */
Contact::Contact () :   
        first_name(""), 
        last_name(""), 
        nickname(""), 
        phone_number(""), 
        darkest_secret("")
{}

void	Contact::print_column(int idx)
{
	cout << "|         " << idx << "|";
	print_value(first_name);
	print_value(last_name);
	print_value(nickname);
	cout << endl;
}

void	Contact::print_contact_info(int id)
{
	cout << endl << CONTACT_ID << id << endl;
	cout << FIRST_NAME << first_name << endl;
	cout << LAST_NAME << last_name << endl;
	cout << NICKNAME << nickname << endl;
	cout << PHONE_NUMBER << phone_number << endl;
	cout << DARKEST_SECRET << darkest_secret << endl;
}
