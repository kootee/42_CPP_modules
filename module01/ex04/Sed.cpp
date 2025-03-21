/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:11:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 12:03:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed (std::string filename, std::string s1, std::string s2)
    :   _filename(filename), 
        _s1(s1), 
        _s2(s2)
{}

std::string    Sed::replace_strings(std::string const &line)
{
    std::size_t         current_pos = 0;
    std::size_t         found = 0;
    std::stringstream   replaced;
    
    if (_s1.size() == 0)
        return(line);
    while (true)
    {
        found = line.find(_s1, current_pos);
        if (found == std::string::npos)
        {
            replaced << line.substr(current_pos);
            return (replaced.str());   
        }
        replaced << line.substr(current_pos, found - current_pos);
        replaced << _s2;
        current_pos = found + _s1.size();
    }
}

int    Sed::run_sed(void)
{
    std::stringstream   text_buffer;
    std::ifstream       in_file;
    std::ofstream       out_file;
    std::string         out_filename = _filename + ".replace";
    
    in_file.open(_filename);
    if (!in_file.is_open())
    {
        std::cout << "error opening infile" << std::endl;
        return (1);
    }
    out_file.open(out_filename);
    if (!out_file.is_open())
    {
        std::cout << "error opening outfile" << std::endl;
        return (1);
    }
    text_buffer << in_file.rdbuf();
    out_file << this->replace_strings(text_buffer.str());
    in_file.close();
    out_file.close();
    return (0);
}