/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:58 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 14:05:51 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal(): type(""){
}

Animal::~Animal(){
    std::cout << "Some Animal has been deconstructed" << std::endl;
}

Animal::Animal(const Animal& other){
    *this = other;
}

Animal& Animal::operator=(const Animal& other){
    if (this == &other){
        return *this;
    }
    type = other.type;
    return (*this);
}
std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound() const {
    std::cout << "i'm an animal and i make animal sounds" << std::endl;
}
void Animal::utterIdea() const {}
void Animal::getIdea(const std::string idea){
    std::cout << "i dont know what to do with this " << idea << std::endl;
}
