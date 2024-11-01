/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:05:32 by ktoivola          #+#    #+#             */
/*   Updated: 2024/11/01 09:51:48 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _ideaCount(0) { std::cout << "Fresh brain created\n"; }

Brain::Brain(const Brain& to_copy)
{
    for(unsigned int i = 0; i < to_copy._ideaCount; i++) {
            _ideas[i] = to_copy._ideas[i];
    }
    _ideaCount = to_copy._ideaCount;
    std::cout << "Brain was copied\n"; 
}

Brain &Brain::operator=(const Brain& to_copy)
{
    if (this == &to_copy)
        return (*this);
    for(unsigned int i = 0; i < to_copy._ideaCount; i++)
        _ideas[i] = to_copy._ideas[i];
    _ideaCount = to_copy._ideaCount;
    std::cout << "Brain was copied with assignment operator\n";
    return *this;
}

Brain::~Brain() { std::cout << "Brain destroyed\n"; }

void    Brain::setIdea(std::string newIdea)
{
    if (_ideaCount == 100) {
        std::cout << "Brain overloaded... resetting...\n";
        _ideaCount = 0;
    }
    _ideas[_ideaCount++] = newIdea;
}

void    Brain::readMind()
{
    for (unsigned int i = 0; i < _ideaCount; i++)
        std::cout << i << ": " << _ideas[i] << std::endl;
}