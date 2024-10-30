/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:34:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 11:39:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice&);
        ~Ice();

        Ice& operator=(const Ice&);
        
        Ice *clone() const override;
        
};