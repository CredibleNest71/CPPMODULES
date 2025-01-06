/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:04:49 by mresch            #+#    #+#             */
/*   Updated: 2025/01/06 17:23:04 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.h"
#include "../includes/Bureaucrat.h"

AForm::AForm(): name("some name"), target(NULL), grade(150), exec(0), signd(false) {}
AForm::AForm(int grade, int exec, std::string target, std::string name) : name(name), target(target), grade(grade), exec(exec), signd(false) {}
AForm::~AForm(){}
AForm::AForm(const AForm& copy) : target(copy.target), grade(copy.grade), exec(copy.exec) {}
AForm& AForm::operator=(const AForm& copy){
    this->signd = copy.signd;
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Grade too high...");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Grade too low...");
}

const char* AForm::CannotExecuteNotSigned::what() const throw(){
    return ("Cannot execute unsigned form...");
}
std::string AForm::getName() const{
    return name;
}
int         AForm::getGrade() const{
    return grade;
}
bool        AForm::getSigned() const{
    return signd;
}
int         AForm::getExec() const{
    return exec;
}
std::string AForm::getTarget() const{
    return target;
}
bool        AForm::beSigned(Bureaucrat& dan){
    if (dan.getGrade() <= grade){
        signd = true;
        return true;
    }
    else {
        throw(GradeTooLowException());
    }
    return false;
}

bool            AForm::check(Bureaucrat const & bu) const{
    if (bu.getGrade() > getExec()){
        throw GradeTooLowException();
        return (false);
    }
    if (!getSigned()){
        throw CannotExecuteNotSigned();
        return (false);
    }
    return (true);
}

std::ostream& operator<<(std::ostream& os, const AForm& sheet){
    os << "Form: " << sheet.getName() << " [" << sheet.getGrade() << "]";
    if (sheet.getSigned())
        os << "[\u2713]";
    else
        os << "[\u2A09]";
    return os;
}
