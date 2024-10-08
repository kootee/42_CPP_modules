/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:11:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/08 12:59:52 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed (std::string filename, std::string s1, std::string s2)
    : filename(filename), s1(s1), s2(s2) {}

std::string    Sed::replace_strings(std::string const &line)
{
    std::size_t         current_idx = 0;
    std::size_t         found = 0;
    std::stringstream   replaced;    
    
    while (true)
    {
        found = line.find(s1);
        if (found == std::string::npos)
            break ;
        replaced << line.substr(current_idx, found - current_idx);
        replaced << s2;
        current_idx = found + s1.size();
    }
    return (replaced.str());
}

void    Sed::run_sed(void)
{
    std::ifstream   in_file;
    std::ofstream   out_file;
    std::string     out_filename;
    std::string     line;

    out_filename = filename + ".replace";
    
    in_file.open(filename);
    out_file.open(out_filename);
    if (in_file.is_open() && out_file.is_open())
    {
        while (getline(in_file, line))
        {
            line = this->replace_strings(line);
            out_file << line;
        }
        in_file.close();
        out_file.close();
    }
    else
        std::cout << "outfile error" << std::endl; // handle error
}