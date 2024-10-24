/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:52:42 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/23 13:07:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	protected:
			std::string type;
	public:
			Cat();
			Cat(const Cat&);
			~Cat();

			Cat& operator=(const Cat&);
};