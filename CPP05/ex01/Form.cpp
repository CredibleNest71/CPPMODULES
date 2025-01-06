/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:04:49 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:33:40 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"
#include "Bureaucrat.h"

Form::Form(): name("some Document"), grade(150), exec(1), signd(false) {}
Form::Form(std::string name, int grade) : name(name), grade(grade), exec(1), signd(false) {}
Form::~Form(){}
Form::Form(const Form& copy) : name(copy.name), grade(copy.grade), exec(1) {}
Form& Form::operator=(const Form& copy){
    this->signd = copy.signd;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade too high...");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade too low...");
}
std::string Form::getName() const{
    return name;
}
int         Form::getGrade() const{
    return grade;
}
int        Form::getExec() const{
    return exec;
}

bool        Form::getSigned() const{
    return signd;
}
bool        Form::beSigned(Bureaucrat& dan){
    if (dan.getGrade() <= grade){
        signd = true;
        return true;
    }
    else {
        throw(GradeTooLowException());
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Form& sheet){
    os << "Form: " << sheet.getName() << " [" << sheet.getGrade() << "]";
    if (sheet.getSigned())
        os << "[\u2713]";
    else
        os << "[\u2A09]";
    return os;
}
