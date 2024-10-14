/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:54:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/14 10:19:40 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
		int					_fixed_pt;
		static const int	_bits;
public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator= (const Fixed& fixed);
		~Fixed() {};

};

#endif