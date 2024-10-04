/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:00:30 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/04 14:29:47 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>    // input and output
# include <string>      // strings
# include <cctype>      // character modifications
# include <limits>      // limits
# include "Contact.hpp" // contact class definitions

# define PROMPT             "Enter phonebook command: "
# define EXIT_MSG           "Exiting phonebook"
# define COLUMNS            "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|"
# define SEARCH_PROMPT      "Enter index to display: "
# define INVALID_SEARCH_ID  "Invalid search value"
# define FIRST_NAME         "First name: "
# define LAST_NAME          "Last name: "
# define NICKNAME           "Nickname: "
# define PHONE_NUMBER       "Phone number: "
# define DARKEST_SECRET     "Deepest darkest secret: "

using namespace std;

class	PhoneBook
{
	Contact	contacts[8];
public:
	static int	index;
    int         status;
	void        search_contact();
	void        add_contact(); 
};

#endif