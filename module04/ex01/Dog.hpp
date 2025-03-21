/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:07:58 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 16:18:34 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
			Brain *_brain;
	public:
			Dog();
			Dog(const Dog&);
			~Dog();

			Dog& operator=(const Dog&);

			void	makeSound(void) const override;
			void    setIdea(std::string);
			void	readMind(void);
};