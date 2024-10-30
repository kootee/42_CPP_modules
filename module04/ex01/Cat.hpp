/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:52:42 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 16:20:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
			Brain *_brain;
	public:
			Cat();
			Cat(const Cat&);
			~Cat();

			Cat& operator=(const Cat&);

			void	makeSound(void) const override;
			void    setIdea(std::string);
			void    readMind();
};