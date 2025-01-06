/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:04:46 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:25:53 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include "AForm.h"
# include "Bureaucrat.h"
# define SHRUB_GRADE 145
# define SHRUB_EXEC 137

class ShrubberyCreationForm : public AForm {
public: 
//CONSTRUCTORS
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &);
    ~ShrubberyCreationForm();
// MEMBER
    bool execute(Bureaucrat const &bu) const;
};
#endif