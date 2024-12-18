/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:47:46 by mresch            #+#    #+#             */
/*   Updated: 2024/12/12 15:05:26 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <cstring>
# include <iostream>
# include <stdexcept>
# include "AForm.h"

class Bureaucrat
{
private:
    const std::string   name;
    int             grade;
    
public:

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& john);

    Bureaucrat& operator= (const Bureaucrat& john);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    

    int                 getGrade() const;
    std::string         getName() const;
    void                incGrade(int amount);
    void                decGrade(int amount);
    void                signForm(AForm& form);
    void                executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& matt);
#endif