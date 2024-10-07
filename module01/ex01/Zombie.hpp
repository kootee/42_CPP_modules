/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:09:26 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/07 14:29:06 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define BRAINS ": BraiiiiiiinnnzzzZ..."

class   Zombie
{
	std::string name;
public:
    void        announce(void);
    void        init_zombie(std::string name);
    Zombie      (std::string name);
    Zombie      ();
};

Zombie  *zombieHorde(int N, std::string name);

#endif