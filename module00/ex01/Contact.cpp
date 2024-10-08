/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:48:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/08 12:42:11 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Contact class parameters constructor */
Contact::Contact (std::string a, std::string b, std::string c, std::string d, std::string e)
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

void	print_value(std::string str)
{
	size_t	len;

	len = str.size();
	if (len >= 10)
	{
        for (int i = 1; i < 10; i++)
            std::cout << str[i];
		std::cout << ".|";
	}
	else
	{
		for (int i = 0; i < (10 - len); i++)
			std::cout << " ";
		std::cout << str << "|";
	}
}

void	Contact::print_column(int idx)
{
	std::cout << "|         " << idx << "|";
	print_value(first_name);
	print_value(last_name);
	print_value(nickname);
	std::cout << std::endl;
}

void	Contact::print_contact_info(int id)
{
	std::cout << std::endl << CONTACT_ID << id << std::endl;
	std::cout << FIRST_NAME << first_name << std::endl;
	std::cout << LAST_NAME << last_name << std::endl;
	std::cout << NICKNAME << nickname << std::endl;
	std::cout << PHONE_NUMBER << phone_number << std::endl;
	std::cout << DARKEST_SECRET << darkest_secret << std::endl;
}
