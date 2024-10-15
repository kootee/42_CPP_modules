/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:09:26 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/15 15:55:29 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define BRAINS ": BraiiiiiiinnnzzzZ..."
# define DESTROY " was destroyed by the destructor"

class   Zombie
{
	std::string _name;
public:
    Zombie  ();             // Default constructor
    Zombie  (std::string);  // Parameterized constructor
    ~Zombie ();             // Destructor
    
    void        announce(void);
    void        init_zombie(std::string);
};

Zombie  *zombieHorde(int N, std::string name);

#endif