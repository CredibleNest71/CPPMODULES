/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:32:38 by mresch            #+#    #+#             */
/*   Updated: 2024/12/18 16:57:58 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H
# include "Bureaucrat.h"
# include "AForm.h"
# include "PresidentialPardonForm.h"
# include "RobotomyRequestForm.h"
# include "ShrubberyCreationForm.h"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern &operator=(const Intern& other);

    AForm *makeForm(std::string form, std::string target);
    class InvalidFormException : public std::exception {
    public:
        const char *what() const throw();
    };
};


#endif