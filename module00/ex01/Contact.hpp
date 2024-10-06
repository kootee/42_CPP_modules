/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:50:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/04 18:49:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

using namespace std;

class	Contact 
{
	string  first_name, last_name, nickname;
	string	phone_number;
	string  darkest_secret;
	
public:
	void	print_column(int id);
	void    print_contact_info(int id);
	Contact (string a, string b, string c, string d, string e);
    Contact ();
};

#endif