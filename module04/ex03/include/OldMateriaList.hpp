/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OldMateriaList.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:37:48 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/31 13:50:24 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "Node.hpp"

class OldMateriaList {
	private:
		Node*	_head;
	public:
		OldMateriaList();
		~OldMateriaList();
		OldMateriaList(const OldMateriaList&);

		OldMateriaList &operator=(const OldMateriaList &);

		void	insertMateria(AMateria *m);
		void	deleteAllMateria();
};
