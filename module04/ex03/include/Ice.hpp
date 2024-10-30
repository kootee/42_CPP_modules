/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:34:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 15:37:32 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/*  Concrete Class derived from Abstract Class Materia. 
    It has to override the following (pure virtual) base class functions:
        - Clone
        - Destructor
    Additional overridden functions:
        - Use   */
class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice&);
        ~Ice() override;

        Ice& operator=(const Ice&);
        
        Ice *clone() const override;
        void use(ICharacter &) override;
};