/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:44:04 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:25:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include "AForm.h"
# include "Bureaucrat.h"
# include <cstdlib> 
# include <ctime>
# define ROBO_GRADE 72
# define ROBO_EXEC 45

class RobotomyRequestForm : public AForm {
public: 
//CONSTRUCTORS
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm &);
    ~RobotomyRequestForm();
// MEMBER
    bool execute(Bureaucrat const &bu) const;
};
#endif