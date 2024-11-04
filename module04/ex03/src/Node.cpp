/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:43 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 14:54:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node() { _materia = nullptr; _next = nullptr; }

Node::Node(AMateria* m) { _materia = m; _next = nullptr; }

Node::Node(const Node &to_copy)  {
	if (to_copy._materia != nullptr)
        _materia = to_copy._materia->clone();
    else
        _materia = nullptr;
}

Node::~Node() { std::cout << "Node destroyed\n"; }

Node &Node::operator=(const Node &to_copy) {
	if (this == &to_copy)
		return (*this);
	if (to_copy._materia)
		_materia = to_copy._materia->clone();
	return (*this);
}

void	Node::deleteNode(void) {
	delete _materia;
	_materia = nullptr;
	_next = nullptr;
}