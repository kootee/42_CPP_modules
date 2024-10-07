/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:50:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 13:12:12 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	std::string  first_name, last_name, nickname;
	std::string	phone_number;
	std::string  darkest_secret;
	
public:
	void	print_column(int id);
	void    print_contact_info(int id);
	Contact (std::string a, std::string b, std::string c, std::string d, std::string e);
    Contact ();
};

#endif