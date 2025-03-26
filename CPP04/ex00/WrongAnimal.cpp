/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:42 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 10:37:17 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(): type(""){}

WrongAnimal::~WrongAnimal(){
    if (!type.empty()){
        std::cout << "A " << type << " has been \'deconstructed\'" << std::endl;
    }
    else {
        std::cout << "Some WrongAnimal has been deconstructed" << std::endl;
    }
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this == &other){
        return *this;
    }
    type = other.type;
    return (*this);
}
std::string WrongAnimal::getType() const{
    return (this->type);
}

void WrongAnimal::makeSound() const {
    std::cout << "i'm a WrongAnimal and i make WrongAnimal sounds" << std::endl;
}