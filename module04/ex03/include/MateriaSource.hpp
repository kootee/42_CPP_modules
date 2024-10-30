/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:19:17 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 14:29:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

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