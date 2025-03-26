/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:52:10 by mresch            #+#    #+#             */
/*   Updated: 2024/11/08 19:54:37 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include "ClapTrap.h"

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in gate-guarding-mode :o " << std::endl ;
}

ScavTrap::ScavTrap() : ClapTrap(){
    _name = "NONAME";
    _hp = 100;
    _energy = 50;
    _dmg = 20;
    std::cout << "it's a SCAVTRAP!! :O" << std::endl ;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
    _hp = 100;
    _energy = 50;
    _dmg = 20;
    std::cout << "it's a SCAVTRAP!! :O" << std::endl ;
}

ScavTrap::~ScavTrap(){
    std::cout << "Scavtrap " << _name << " says  \"BYE!\"" << std::endl ;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(){
    *this = cpy;
    std::cout << "ScavTrap was copied :)" << std::endl ;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& copy) {
    _name = copy._name;
    _hp = copy._hp;
    _energy = copy._energy;
    _dmg = copy._dmg;
    std::cout << "Scav Assignement was used" << std::endl ;
    return *this;
}
void ScavTrap::attack(const std::string& target){
    if (_energy == 0)
    {
        std::cout << "ScavTrap " << _name << " is too tired :(\n";
        return ;
    }
    _energy--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " for " << _dmg << " damage\n";
}