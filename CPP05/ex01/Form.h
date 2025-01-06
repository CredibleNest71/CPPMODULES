/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:53:25 by mresch            #+#    #+#             */
/*   Updated: 2024/12/11 14:07:39 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
//# include "Bureaucrat.h"
# include <cstring>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {
private:
//ATRIBUTES
    const std::string   name;
    const int           grade;
    bool                signd;
    
public:
//CON AND DESTRUCTORS
    Form();
    Form(std::string name, int grade);
    ~Form();
    Form(const Form& copy);
    Form& operator=(const Form& copy);

//GETTERS AND SETTERS
    std::string getName() const;
    int         getGrade() const;
    bool        getSigned() const;

//MEMBER FUNCS
    bool        beSigned(Bureaucrat& dan);

//EXCEPTIONS
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& sheet);

#endif