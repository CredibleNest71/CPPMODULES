/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:07 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:26:49 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.h"
PresidentialPardonForm::PresidentialPardonForm() : AForm(PRES_GRADE, PRES_EXEC, "", "Presidential Pardon Form") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PRES_GRADE, PRES_EXEC, target, "Presidential Pardon Form") {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm(PRES_GRADE, PRES_EXEC, cpy.getTarget(), "Presidential Pardon Form"){}
PresidentialPardonForm::~PresidentialPardonForm(){}
bool PresidentialPardonForm::execute(Bureaucrat const &bu) const{
    if (!check(bu))
        return false;
    std::cout << getTarget() << " was pardoned by Zaphod Beeblebrox" << std::endl;
    return true;
}