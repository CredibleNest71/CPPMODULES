/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:43:48 by mresch            #+#    #+#             */
/*   Updated: 2024/12/12 15:24:08 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.h"
#include "includes/AForm.h"
#include "includes/ShrubberyCreationForm.h"
#include "includes/RobotomyRequestForm.h"
#include "includes/PresidentialPardonForm.h"

int main(){
    Bureaucrat matt("Matt", 1);
    Bureaucrat dave("Dave", 140);
    
    PresidentialPardonForm b("PardonMePls");
    ShrubberyCreationForm c("Tree");
    RobotomyRequestForm d("whatevenisrobotomy");
        
//SIGNING
    std::cout << "_________________" << std::endl;
    std::cout << "TESTING SIGNING" << std::endl;
    std::cout << "_________________" << std::endl;
    try {
        b.beSigned(dave);
        c.beSigned(dave);
        d.beSigned(dave);
    }
    catch (...) {
        std::cerr << "Dave messed it up..." << std::endl;
    }

    try {
        b.beSigned(matt);
        c.beSigned(matt);
        d.beSigned(matt);
    }
    catch (...) {
        std::cerr << "Matt messed it up..." << std::endl;
    }

//EXECUTING
    std::cout << "_________________" << std::endl;
    std::cout << "TESTING EXECUTION" << std::endl;
    std::cout << "_________________" << std::endl;

    try {
        dave.executeForm(b);
        dave.executeForm(c);
        dave.executeForm(d);
    }
    catch (...){
        std::cerr << "Dave really shouldnt handle all those Forms" << std::endl;
    }

    try {
        matt.executeForm(b);
        matt.executeForm(c);
        matt.executeForm(d);
    }
    catch (...){
        std::cerr << "Matt really shouldnt handle all those Forms" << std::endl;
    }
    
    return 0;
}