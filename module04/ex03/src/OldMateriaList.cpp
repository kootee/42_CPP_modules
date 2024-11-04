/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OldMateriaList.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:44:40 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 14:51:43 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OldMateriaList.hpp"

OldMateriaList::OldMateriaList() { _head = nullptr; }

OldMateriaList::~OldMateriaList() {
	std::cout << "Old materia list deleted\n";
}

OldMateriaList::OldMateriaList(const OldMateriaList& to_copy) {
	Node *node = to_copy._head;
	
	while (node != nullptr)
	{
		this->insertMateria(to_copy._head->_materia);
		node = to_copy._head->_next;
	}
 }

OldMateriaList& OldMateriaList::operator=(const OldMateriaList &to_copy) {
	if (this == &to_copy)
		return (*this);
	if (to_copy._head)
		*_head = *to_copy._head;
	return (*this);
}

void	OldMateriaList::insertMateria(AMateria *m) {
	Node *newNode = new Node(m); // leaks
	
	if (!_head) {
		_head = newNode;
		return ;
	}
	newNode->_next = _head;
	_head = newNode;
}

void	OldMateriaList::deleteAllMateria(void) {
	Node	*temp;

	while (_head)
	{
		std::cout << "Deleting unequipped materia " << _head->_materia->getType() << std::endl;
		temp = _head->_next;
		_head->deleteNode(); // deletes materia and sets next to null
		delete _head;
		_head = temp;
	}
}