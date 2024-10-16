/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:51:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 12:06:12 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <sstream> // string stream

class Sed
{
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
    public:
        Sed         (std::string, std::string, std::string);
        
        // Class member functions
        int         run_sed(void);
        std::string replace_strings(std::string const &line);
};

#endif