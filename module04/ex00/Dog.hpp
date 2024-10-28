/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:07:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/28 16:45:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	private:
            std::string type;
	public:
			Dog();
			Dog(const Dog&);
			~Dog();

			Dog& operator=(const Dog&);

			void	makeSound(void);
};