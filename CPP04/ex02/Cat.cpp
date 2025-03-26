/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:58:29 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 11:10:11 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain;
}
Cat::~Cat() {
    delete brain;
    std::cout << "DeCatstructor was called" << std::endl;
}
Cat::Cat(const Cat& goodboy) : Animal(goodboy){
    brain = NULL;
    *this = goodboy;
}
Cat& Cat::operator=(const Cat& goodboy){
    if (brain != NULL)
        delete brain;
    if (this == &goodboy)
        return *this;
    type = goodboy.type;
    brain = new Brain(*goodboy.brain);
    return *this;
}

void Cat::makeSound()const{
    std::cout << "miau" << std::endl;
}
void Cat::utterIdea() const{
    brain->getIdeas();
}
void Cat::setIdea(const std::string idea, int idx){
    brain->setIdea(idea, idx);
}
