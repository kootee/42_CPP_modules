/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 08:02:07 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int exit_phonebook(int exit_value)
{
    if (exit_value)
        std::cout << EXIT_MSG << std::endl;
    return (0);
}

int check_search_id(const std::string& str, int phonebook_id)
{
    int id;

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
    id = atoi(str.c_str());
	if ((id > 7 || id < 0) 
        || (phonebook_id == 0 || id > (phonebook_id - 1) % 8))
        {
		    std::cout << OUT_OF_RANGE_ID << std::endl;
            return (-1);
        }
    return (id);
}

int PhoneBook:: index = 0, status = 0;

void	PhoneBook::add_contact()
{
	std::string name, lastname, nickname, number, secret;

    if ((std::cout << FIRST_NAME) &&!getline(std::cin, name))
        return ;
    if ((std::cout << LAST_NAME) && !getline(std::cin, lastname))
        return ;
    if ((std::cout << NICKNAME) && !getline(std::cin, nickname))
        return ;
    if ((std::cout << PHONE_NUMBER) && !getline(std::cin, number))
        return ;
    if ((std::cout << DARKEST_SECRET) && !getline(std::cin, secret))
        return ;
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

int	main()
{
	PhoneBook   phonebook;
	std::string      input;

	while (true)
	{
        if (std::cin.eof())
            return (exit_phonebook(1));
		std::cout << PROMPT;
		if (!getline(std::cin, input))
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