/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:13:17 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/16 10:52:57 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string         brain = "HI THIS IS BRAIN"; 
    std::string         *stringPTR = &brain;    // String pointer to address of brain
    std::string const&  stringREF = brain;      // const reference to brain
    
    std::cout << "Address of string     " << &brain << std::endl;
    std::cout << "Address of stringPTR  " << stringPTR << std::endl;
    std::cout << "Address of stringREF  " << &stringREF << std::endl;
    std::cout << "Value of string       " << brain << std::endl;
    std::cout << "Value of stringPTR    " << *stringPTR << std::endl;
    std::cout << "Value of stringREF    " << stringREF << std::endl;
}