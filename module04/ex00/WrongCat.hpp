/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:58:57 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 10:31:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	    public:
			WrongCat();
			WrongCat(const WrongCat&);
			~WrongCat();

			WrongCat& operator=(const WrongCat&);

			void	makeSound(void) const;
};