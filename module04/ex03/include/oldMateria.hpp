/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldMateria.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:37:48 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 10:44:59 by ktoivola         ###   ########.fr       */
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


