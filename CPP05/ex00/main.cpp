/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:43:48 by mresch            #+#    #+#             */
/*   Updated: 2024/12/18 18:12:11 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(){
    Bureaucrat a;
    Bureaucrat b(a);
    Bureaucrat c("Marc", 100);

    //BUREACRAT TOO HIGH
    try {
        Bureaucrat d("Fred", 200);
        a.incGrade(200);
    }
    catch (Bureaucrat::GradeTooLowException& err )
    {
        std::cout << "Caught: " << err.what() << std::endl;
    }

    //BUREAUCRAT TOO LOW 
    try {
    Bureaucrat d("Fred", 0);
    a.incGrade(0);
    }
    catch (Bureaucrat::GradeTooHighException& err )
    {
        std::cout << "Caught: " << err.what() << std::endl;
    }
    
    std::cout << a << b << c << std::endl;
    
    return 0;
}