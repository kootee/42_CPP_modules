/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:00:30 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/10 10:26:21 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>    // input and output
# include "Contact.hpp" // contact class definitions

# define PROMPT             "Enter phonebook command (ADD/SEARCH/EXIT): "
# define EXIT_MSG           "Exiting phonebook"
# define PHONEBOOK_HEADER   "**********    PHONEBOOK CONTACTS   **********"
# define COLUMNS            "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|"
# define SEARCH_PROMPT      "Enter index to display: "
# define CONTACT_ID         "CONTACT INFORMATION FOR ID "
# define INVALID_SEARCH_ID  "Invalid index"
# define INVALID_INPUT      "Invalid input"
# define OUT_OF_RANGE_ID    "Index out of range"
# define FIRST_NAME         "First name: "
# define LAST_NAME          "Last name: "
# define NICKNAME           "Nickname: "
# define PHONE_NUMBER       "Phone number: "
# define DARKEST_SECRET     "Darkest secret: "

class	PhoneBook
{
	Contact	contacts[8];
public:
	static int	index;
	void        search_contact();
	void        add_contact(); 
};

#endif