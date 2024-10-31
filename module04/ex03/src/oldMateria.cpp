/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldMateria.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:44:40 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 10:45:03 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oldMateria.hpp"

Node::Node() {
	_materia = nullptr;
	_next = nullptr;
}

Node::Node(AMateria* m) { _materia = m; _next = nullptr; }

Node::Node(const Node &to_copy)  {
	*_materia = *to_copy._materia; 
}

Node::~Node() {
	if (_materia)
		delete _materia;
	_next = nullptr;
}

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


oldMateriaList::oldMateriaList() { _head = nullptr; }

oldMateriaList::~oldMateriaList() {}

oldMateriaList::oldMateriaList(const oldMateriaList& to_copy) { *_head = *to_copy._head; }

oldMateriaList& oldMateriaList::operator=(const oldMateriaList &to_copy) {
	if (this == &to_copy)
		return (*this);
	if (to_copy._head)
		*_head = *to_copy._head;
	return (*this);
}

void	oldMateriaList::insertMateria(AMateria *m) {
	Node *newNode = new Node(m);
	
	if (!_head) {
		_head = newNode;
		return ;
	}
	newNode->_next = _head;
	_head = newNode;
}

void	oldMateriaList::deleteAllMateria(void) {
	Node	*temp;
	
	while (_head)
	{
		temp = _head->_next;
		_head->deleteNode(); // deletes materia and sets next to null
		_head = temp;
	}	
}