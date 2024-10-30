/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:02:12 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 15:37:43 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/*  Concrete Class derived from Abstract Class Materia. 
    It has to override the following (pure virtual) base class functions:
        - Clone
        - Destructor
    Additional overridden functions:
        - Use   */
class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure&);
        ~Cure() override;

        Cure& operator=(const Cure&);
        
        Cure *clone() const override;
        void use(ICharacter &) override;
};