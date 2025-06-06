/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:56:34 by mresch            #+#    #+#             */
/*   Updated: 2024/12/18 18:10:57 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

// CANONICAL AND ORTHODOX
    Bureaucrat::Bureaucrat() : name("John"), grade(150) {
        std::cout << "Some Guy named " << name << " has been hired!(Default Constructed)" << std::endl;
    }
    Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
        if (grade < 1)
            throw (GradeTooHighException());
        if (grade > 150)
            throw (GradeTooLowException());
        std::cout << name << " has been hired!(Constructed)" << std::endl;
    }
    Bureaucrat::~Bureaucrat(){
        std::cout << name << " has been fired(Deconstructed)" << std::endl;
    }
    Bureaucrat::Bureaucrat(const Bureaucrat& john) : name(john.name){
        *this = john;
        
        std::cout << "Another Guy named " << name << " has been hired!(Default Constructed)" << std::endl;
    }

    Bureaucrat& Bureaucrat::operator= (const Bureaucrat& john){
        grade = john.grade;
        std::cout << "This new guy " << name << " looks exactly like the other " << john.name << "(Assignement)" << std::endl;
        return *this;
    }


//GETTERS & SETTERS
int           Bureaucrat::getGrade() const{
    return grade;
}
std::string   Bureaucrat::getName() const{
    return name;
}
void                Bureaucrat::decGrade(int amount){
    if (grade + amount > 150)
        throw (GradeTooLowException());
    grade += amount;
}
void                Bureaucrat::incGrade(int amount){
    if (grade - amount < 1)
        throw (GradeTooHighException());
    grade -= amount;
}

// EXCEPTION CLASSES
//Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : msg(msg){}
const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade too high");//msg.c_str();
}
//Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : msg(msg){}
const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade too low....");//msg.c_str();
}

// IO STREAM
std::ostream& operator<<(std::ostream& os, const Bureaucrat& matt){
    os << matt.getName() << ", bureaucrat grade " << matt.getGrade() << std::endl;
    return os;
}
