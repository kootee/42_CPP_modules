/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:19:17 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 10:30:46 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/* Concrete class that implements  the IMateriaSource interface
        Implements the following class functions:
        - learnMateria
        - createMateria          */
class MateriaSource : public IMateriaSource {
    private:
            AMateria* _materiaInventory[4];
    public:
            MateriaSource();
            MateriaSource(const MateriaSource &);
            ~MateriaSource() override;
            
            MateriaSource& operator=(const MateriaSource &);

            // Class member functions
            void        learnMateria(AMateria*) override;
            AMateria    *createMateria(std::string const&) override;
};