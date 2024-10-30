/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:05:18 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/29 16:21:52 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
    private:
            std::string     _ideas[100];
            unsigned int    _ideaCount;
    public:
            Brain();
            Brain(const Brain&);
            ~Brain();

            Brain& operator=(const Brain&);

            void    readMind();
            void    setIdea(std::string);
            
};