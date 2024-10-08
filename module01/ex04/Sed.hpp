/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:51:33 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/08 12:49:29 by ktoivola         ###   ########.fr       */
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
    std::string replace_strings(std::string const &line);
    void        run_sed(void);
};

#endif