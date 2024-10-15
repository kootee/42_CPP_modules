/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:09:26 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:25 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define BRAINS ": BraiiiiiiinnnzzzZ..."
# define DESTROY " was destroyed by the destructor"

class   Zombie
{
    private:
        std::string _name;
    public:
        Zombie  ();             // Default constructor
        Zombie  (std::string);  // Parameterized constructor
        ~Zombie ();             // Destructor
        
        void	announce(void);
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif