/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:35:01 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 13:03:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
    this->weapon = NULL;
}
HumanB::~HumanB(void){}
void	HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

void	HumanB::attack(void) const {
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with their bare hands" << std::endl;
}