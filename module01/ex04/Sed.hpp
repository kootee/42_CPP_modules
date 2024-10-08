/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:51:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/08 16:11:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream> // string stream

class Sed
{
    std::string filename;
    std::string s1;
    std::string s2;
public:
    Sed         (std::string filename, std::string s1, std::string s2);
    int         run_sed(void);
    std::string replace_strings(std::string const &line);
};

#endif