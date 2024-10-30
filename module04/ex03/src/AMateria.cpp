/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:13:53 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 14:05:51 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (std::string const& type) : _type(type) {
    std::cout << "Materia created\n"; }

AMateria::AMateria(const AMateria& to_copy) : _type(to_copy._type) {
    std::cout << "Materia copied\n";
}

AMateria::~AMateria() { std::cout << "Materia destroyed\n"; }

AMateria& AMateria::operator=(const AMateria& to_copy) {
   std::cout << "Materia copied with assign operator\n";
    (void)to_copy;
   return (*this);
}

/* Class member functions */
std::string const &AMateria::getType(void) const { return (_type); }
