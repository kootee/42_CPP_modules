/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:49:54 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:14 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Node {
	public:
		AMateria*   _materia;
		Node*       _next;
		Node();
		Node(AMateria *m);
		Node(const Node&);
		~Node();

		Node &operator=(const Node &);

		void	deleteNode();
};