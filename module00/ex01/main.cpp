/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/10 10:43:05 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int exit_phonebook(int exit_value)
{
	if (exit_value)
		std::cout << EXIT_MSG << std::endl;
	return (0);
}

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

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