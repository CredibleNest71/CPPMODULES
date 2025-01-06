/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:53:25 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:21:24 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H
//# include "Bureaucrat.h"
# include <cstring>
# include <iostream>
# include <stdexcept>
# include <fstream>

class Bureaucrat;

class AForm {
private:
//ATRIBUTES
    const std::string   name;
    const std::string   target;
    const int           grade;
    const int           exec;
    bool                signd;
    
public:
//CON AND DESTRUCTORS
    AForm();
    AForm(int grade, int exec, std::string target, std::string name);
    virtual ~AForm();
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);

//GETTERS AND SETTERS
    std::string getName() const;
    int         getGrade() const;
    bool        getSigned() const;
    int         getExec() const;
    std::string getTarget() const;

//MEMBER FUNCS
    bool            beSigned(Bureaucrat& dan);
    virtual bool    execute(Bureaucrat const & bu) const = 0;
    virtual bool    check(Bureaucrat const & bu) const;

//EXCEPTIONS
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class CannotExecuteNotSigned : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& sheet);

#endif