/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:43:48 by mresch            #+#    #+#             */
/*   Updated: 2024/12/18 18:15:59 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int main(){
    Bureaucrat matt("matt", 20);
    Bureaucrat dave("dave", 140);

    Form b;
    Form c("declaration of something", 50);

    try {
        // dave.signForm(c);
        // dave.signForm(b);
        b.beSigned(dave);
        c.beSigned(dave);
    }
    catch (...) {
        std::cerr << "Dave messed it up..." << std::endl;
    }
    
    matt.signForm(c);
    matt.signForm(b);
    std::cout << "\n" << matt << b << c << std::endl;
    
    return 0;
}