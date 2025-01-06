/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:43:48 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 15:27:35 by mresch           ###   ########.fr       */
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
    catch (Form::GradeTooLowException &err) {
        std::cerr << "Caught: Dave messed it up..." << err.what() << std::endl;
    }
    catch (Form::GradeTooHighException &err) {
        std::cerr << "Caught: Dave messed it up..." << err.what() << std::endl;
    }
    
    matt.signForm(c);
    matt.signForm(b);
    std::cout << "\n" << matt << b << "\n" << c << std::endl;
    
    return 0;
}
