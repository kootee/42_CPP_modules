/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldMateria.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:37:48 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 10:16:17 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Node {
	private:
		AMateria*   _materia;
	public:
		Node*       _next;
		Node();
		Node(AMateria *m);
		Node(const Node&);
		~Node();

		Node &operator=(const Node &);

		void	deleteNode();
};

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

class oldMateriaList {
	private:
		Node*	_head;
	public:
		oldMateriaList();
		~oldMateriaList();
		oldMateriaList(const oldMateriaList&);

		oldMateriaList &operator=(const oldMateriaList &);

		void	insertMateria(AMateria *m);
		void	deleteAllMateria();
};

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

