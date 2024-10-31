/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:34:04 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 13:40:03 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice () : AMateria("ice") { std::cout << "Ice materia created\n"; }

Ice::Ice(const Ice& to_copy) : AMateria(to_copy) { std::cout << "Ice materia copied\n"; }

Ice::~Ice() { std::cout << "Ice materia destroyed\n"; }

Ice& Ice::operator=(const Ice &to_copy) {
	std::cout << "Ice materia copied with assign operator\n";
	(void)to_copy;
	return (*this);
}

Ice* Ice::clone(void) const { 
	std::cout << "Cloned Ice materia\n";
	return (new Ice(*this)); 
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}