/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/10 10:37:49 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook:: index = 0;

int check_search_id(const std::string& str, int phonebook_id)
{
	if (str.size() > 2)
	{
	   std::cout << INVALID_INPUT << std::endl;
		return (-1); 
	}
	std::string::const_iterator c = str.begin();
	while (c != str.end())
	{
		if (!isdigit(*c))
		{
			std::cout << INVALID_INPUT << std::endl;
			return (-1);
		}
		c++;   
	}
	int id = atoi(str.c_str());
	if ((id > 7 || id < 0) 
		|| (phonebook_id == 0 
		|| (phonebook_id < 8 && id > (phonebook_id - 1) % 8)
		))
	{
			std::cout << OUT_OF_RANGE_ID << std::endl;
			return (-1);
	}
	return (id);
}

std::string	get_contact_info(std::string prompt)
{
	std::string	input;
	
	while (true)
	{
		if ((std::cout << prompt) && !getline(std::cin, input))
			break ;
		if (input != "")
			break ;
	}	
	return (input);
}

void	PhoneBook::add_contact()
{
	std::string name, lastname, nickname, number, secret;

	name = get_contact_info(FIRST_NAME);
	lastname = get_contact_info(LAST_NAME);
	nickname = get_contact_info(NICKNAME);
	number = get_contact_info(PHONE_NUMBER);
	secret = get_contact_info(DARKEST_SECRET);
	contacts[index % 8] = Contact (name, lastname, nickname, number, secret);
	index++;
}

void	PhoneBook::search_contact()
{
	std::string		input;
	long int	id_print;

	id_print = -1;
	std::cout << std::endl << PHONEBOOK_HEADER << std::endl << COLUMNS << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_column(i);
	while (true)
	{
		std::cout << SEARCH_PROMPT;
		if (!getline(std::cin, input))
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
