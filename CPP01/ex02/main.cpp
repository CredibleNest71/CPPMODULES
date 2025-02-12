/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:55:46 by codespace         #+#    #+#             */
/*   Updated: 2024/06/17 12:57:07 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;
    
    std::cout << "strADR:			" << &brain << std::endl;
    std::cout << "strPTR:			" << stringPTR << std::endl; 
    std::cout << "strREF:			" << &stringREF << std:: endl;    
    
    std::cout << "STRING:			" << brain << std::endl;
    std::cout << "strPTR:			" << *stringPTR << std::endl; 
    std::cout << "strREF:			" << stringREF << std:: endl;

    return 0;
}