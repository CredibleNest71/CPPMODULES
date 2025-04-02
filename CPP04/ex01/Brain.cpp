/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:50 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 11:36:51 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <fstream>

Brain::Brain(){
    for (int i = 0; i < 100; i++){
        ideas[i] = "no idea";
    }
}
Brain::~Brain(){
    std::cout << "this brain is dead" << std::endl;
}
Brain::Brain(const Brain& other){
    // for (int i = 0; i < 100; i++){
    //     ideas[i] = other.ideas[i];
    // }
    *this = other;
}
Brain& Brain::operator=(const Brain& other){
    for (int i = 0; i < 100; i++){
        ideas[i].assign(other.ideas[i]);
    }
    return *this;
}
void Brain::getIdeas() const{
    std::cout << ideas[0] << std::endl;
}
void Brain::setIdea(const std::string idea, int idx){
    if (idx < 0 || idx > 99){
        std::cerr << "idea idx out of range!" << std::endl;
        return;
    }
    ideas[idx] = idea;
}
