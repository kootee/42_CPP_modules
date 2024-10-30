/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:06 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 15:14:00 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

/* Abstract Base Class Materia */
class AMateria 
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const& type);  // Constructor
        AMateria(const AMateria&);          // Copy constructor
        virtual ~AMateria() = 0;            // Pure virtual Destructor

		AMateria& operator=(const AMateria&); // Assignment operator overload
        
        // Class member functions
        std::string const & getType() const;    // Returns materia of the type
        virtual AMateria* clone() const = 0;    // Pure virtual function
        virtual void use(ICharacter& target);
};