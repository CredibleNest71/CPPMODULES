/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:02 by mresch            #+#    #+#             */
/*   Updated: 2024/11/13 13:00:45 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(){
    std::cout << "An unknown Claptrap appeared" << std::endl;
    _name = "NO-NAME";
    _hp = 10;
    _energy = 10;
    _dmg = 0;
}
ClapTrap::ClapTrap(std::string name):_name(name){
    _hp = 10;
    _energy = 10;
    _dmg = 0;
    std::cout << "A new Claptrap has been constructed! He shall be known as " << name << "\n";
}
ClapTrap::~ClapTrap(){
    std::cout << "Claptrap " << this->_name << " has been deconstructed...\n";
}
ClapTrap::ClapTrap(const ClapTrap& cpy){
    *this = cpy;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& copy){
    _name = copy._name;
    _hp = copy._hp;
    _energy = copy._energy;
    _dmg = copy._dmg;
    return *this;
}
void ClapTrap::attack(const std::string& target){
    if (this->_energy == 0)
    {
        std::cout << "Claptrap " << this->_name << " is too tired :(\n";
        return ;
    }
    this->_energy--;
    std::cout << "Claptrap " << this->_name << " attacks " << target << " for " << this->_dmg << " damage\n";
}
void ClapTrap::takeDamage(unsigned int amount){
    this->_hp -= amount;
    std::cout << "\"OUCH!\" says " << this->_name << ". He has taken " << amount << " damage\n";
}
void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energy == 0)
    {
        std::cout << "Claptrap " << this->_name << " is too tired :(\n";
        return ;
    }
    this->_hp += amount;
    std::cout << "Claptrap " << this->_name << " repaired itself for " << (int)amount << " points\n";
}