/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:37:45 by mresch            #+#    #+#             */
/*   Updated: 2024/12/18 18:36:23 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.h"

Intern::Intern(){
    std::cout << "Hello new Intern" << std::endl;
}
Intern::Intern(const Intern& other){
    (void) other;
    std::cout << "Hello new Intern that looks like the other one" << std::endl;
}
Intern &Intern::operator=(const Intern& other){
    (void) other;
    return *this;
}
Intern::~Intern(){
    std::cout << "Bye Intern" << std::endl;
}

static std::string processString(const std::string& str){
    std::string result;
    for (unsigned long i = 0; i < str.size(); i++){
        if (!std::isspace(static_cast<unsigned int>(str[i])))
            result += std::tolower(static_cast<unsigned int>(str[i]));
    }
    return result;
}

static AForm *makePresident(const std::string target){
    return (new PresidentialPardonForm(target));
}
static AForm *makeRobotomy(const std::string target){
    return (new RobotomyRequestForm(target));
}
static AForm *makeShrubbery(const std::string target){
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target){
    AForm *final;
    std::string compare = processString(form);
    std::string names[3] = { "presidentialpardon", "robotomyrequest", "shrubberycreation"};
    AForm *(*createForm[3])(std::string target) = {makePresident, makeRobotomy, makeShrubbery};
    for (int i = 0; i < 3; i++){
        if (names[i] == compare){
            final = createForm[i](target);
            std::cout << "Intern creates " << *final << std::endl;
            return (final);
        }
    }
    throw(InvalidFormException());
}

const char *Intern::InvalidFormException::what() const throw(){
    return ("Invalid Form Name");
}
