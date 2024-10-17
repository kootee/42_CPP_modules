/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:54:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/17 11:56:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEFAULT_CONST	"Default constructor called"
# define COPY_CONST		"Copy constructor called"
# define DESTRUCTOR		"Destructor called"
# define COPY_ASSIGN	"Copy assignment operator called"
# define GET_RAW_BITS	"Get raw bits called"
# define SET_RAW_BITS	"Set raw bits called"

class Fixed
{
	private:
			int					_fixed_pt;
			static const int	_bits = 8;
	public:
			Fixed(); 					// Default constructor
			Fixed(const Fixed& copy);	// Copy constructor
			~Fixed(); 					// Destructor
			
			Fixed& operator= (const Fixed& fixed);	// Assignment operator overload
			
			// Class member functions
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif