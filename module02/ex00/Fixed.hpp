/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:54:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:46 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEFAULT_CONST	"Default constructor called"
# define COPY_CONST		"Copy constructor called"
# define DESTRUCTOR		"Destructor called"
# define COPY_ASSIGN	"Copy assignment operator called"
# define GET_RAW_BITS	"getRawBits member function called"
# define SET_RAW_BITS	"setRawBits member function called"

class Fixed
{
	private:
			int					_fixed_pt;
			static const int	_bits;
	public:
			Fixed(); 					// Default constructor
			Fixed(const Fixed& copy);	// Copy constructor
			~Fixed(); 					// Destructor
			
			Fixed& operator= (const Fixed& fixed);	// Copy assignment operator overload
			
			// Class member functions
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif