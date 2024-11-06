/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:50 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 12:09:59 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <fstream>

Brain::Brain(){
    for (int i = 0; i < 100; i++){
        ideas[i] = "no idea";
    }
    // std::string filename = "ideas.txt";
    // std::cout << "this is a brain talking" << std::endl;
    // std::ifstream	infile(filename.c_str());
    // std::getline(infile, ideas[0]);
}
Brain::~Brain(){
    std::cout << "this brain is dead" << std::endl; 
}
Brain::Brain(const Brain& other){
    *this = other;
}
Brain Brain::operator=(const Brain& other){
    if (this == &other)
        return *this;
    else
        std::copy(other.ideas, other.ideas + 100, ideas);
    return *this;
}
void Brain::getIdeas() const{
    std::cout << ideas[0] << std::endl;
}
void Brain::setIdea(const std::string idea){
    ideas[0] = idea;
    std::cout << "new idea: " << ideas[0] << idea << std::endl;
}
