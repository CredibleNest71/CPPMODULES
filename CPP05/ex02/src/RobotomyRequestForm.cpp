/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:48:37 by mresch            #+#    #+#             */
/*   Updated: 2024/12/12 15:16:25 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBO_GRADE, ROBO_EXEC, "", "Robotomy Request Form"){}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(ROBO_GRADE, ROBO_EXEC, target, "Robotomy Request Form"){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : AForm(ROBO_GRADE, ROBO_EXEC, cpy.getTarget(), "Robotomy Request Form"){}
RobotomyRequestForm::~RobotomyRequestForm(){}
bool RobotomyRequestForm::executeForReal()const{
    std::srand(std::time(0));

    int rand = std::rand();
    std::cout << "bbrrrrrrrr drrrriiiiilll ..... brrrrrrrr drrrrrilllllll ...." << std::endl;
    if (rand % 2){
        std::cout << getTarget() << " has been robotomized" << std::endl;
        return true;
    }
    else {
        std::cout << "Failed to robotomize " << getTarget() << std::endl;
        return false;
    }
}