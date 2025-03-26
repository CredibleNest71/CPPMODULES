/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:58 by mresch            #+#    #+#             */
/*   Updated: 2024/11/07 14:20:56 by mresch           ###   ########.fr       */
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
