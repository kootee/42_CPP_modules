/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:54:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/17 10:35:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
			int					_fixed_pt;
			static const int	_bits;
	public:
			Fixed(); 					// default constructor
			Fixed(const Fixed& copy);	// copy constructor
			Fixed& operator= (const Fixed& fixed);	// copy assignment operator overload
			~Fixed() {}; // destructor
			
			// Member functions
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif