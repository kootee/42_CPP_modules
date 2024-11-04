/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:02:36 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 13:40:18 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure () : AMateria("cure") { std::cout << "Cure materia created\n"; }

Cure::Cure(const Cure& to_copy) : AMateria(to_copy) { std::cout << "Cure materia copied\n"; }

Cure::~Cure() { std::cout << "Cure materia destroyed\n"; }

Cure& Cure::operator=(const Cure &to_copy) {
   std::cout << "Cure materia copied with assign operator\n";
    (void)to_copy;
    return (*this);   
}

Cure* Cure::clone(void) const { 
    std::cout << "Cloned Cure materia\n";
    return (new Cure(*this)); 
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}