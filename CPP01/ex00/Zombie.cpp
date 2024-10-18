/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:03:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 13:14:10 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void){
    std::cout << "<" << this->name << ">: " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie(void){
    std::cout << "bye " << this->name << std::endl;
}