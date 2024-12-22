/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:07 by mresch            #+#    #+#             */
/*   Updated: 2024/12/12 15:17:00 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.h"
PresidentialPardonForm::PresidentialPardonForm() : AForm(PRES_GRADE, PRES_EXEC, "", "Presidential Pardon Form") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PRES_GRADE, PRES_EXEC, target, "Presidential Pardon Form") {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm(PRES_GRADE, PRES_EXEC, cpy.getTarget(), "Presidential Pardon Form"){}
PresidentialPardonForm::~PresidentialPardonForm(){}
bool PresidentialPardonForm::executeForReal() const{
    std::cout << getTarget() << " was pardoned by Zaphod Beeblebrox" << std::endl;
    return true;
}