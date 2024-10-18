/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:13:50 by mresch            #+#    #+#             */
/*   Updated: 2024/10/18 15:44:27 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

Brain::Brain(){}
Brain::~Brain(){}
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