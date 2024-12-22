/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:57:01 by mresch            #+#    #+#             */
/*   Updated: 2024/12/12 15:16:33 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include "AForm.h"
# include "Bureaucrat.h"
# define PRES_GRADE 25
# define PRES_EXEC 5

class PresidentialPardonForm : public AForm {
public: 
//CONSTRUCTORS
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm &cpy);
    ~PresidentialPardonForm();
// MEMBER
    bool executeForReal()const;
};
#endif