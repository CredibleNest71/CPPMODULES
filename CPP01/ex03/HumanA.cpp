/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:35:01 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 13:02:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
HumanA::~HumanA(void){}

void	HumanA::attack(void) const {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}