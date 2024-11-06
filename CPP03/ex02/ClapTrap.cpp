/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:02 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 10:43:26 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

//CONSTRUCTORS
ClapTrap::ClapTrap(){
    std::cout << "An unknown Claptrap appeared" << std::endl;
    _name = "NO-NAME";
    _hp = 0;
    _energy = 0;
    _dmg = 0;
}

ClapTrap::ClapTrap(std::string name):_name(name){
    std::cout << "A new Claptrap has been constructed! He shall be known as " << name << "\n";
    this->_hp = 0;
    this->_energy = 20;
    this->_dmg = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << "Claptrap " << this->_name << " has been deconstructed...\n";
}

ClapTrap::ClapTrap(const ClapTrap& cpy){
    *this = cpy;
}

//OPERATORS
ClapTrap& ClapTrap::operator= (const ClapTrap& copy){
    _name = copy._name;
    _hp = copy._hp;
    _energy = copy._energy;
    _dmg = copy._dmg;
    std::cout << "Clap Assignement was used" << std::endl ;
    return *this;
}

//METHODS
void ClapTrap::attack(const std::string& target){
    if (_energy == 0)
    {
        std::cout << "Claptrap " << _name << " is too tired :(\n";
        return ;
    }
    _energy--;
    std::cout << "Claptrap " << _name << " attacks " << target << " for " << _dmg << " damage\n";
}

void ClapTrap::takeDamage(unsigned int amount){
    _hp -= amount;
    std::cout << "\"OUCH!\" says " << _name << ". He has taken " << amount << " damage\n";
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energy == 0)
    {
        std::cout << "Claptrap " << _name << " is too tired :(\n";
        return ;
    }
    _hp += amount;
    std::cout << "Claptrap " << _name << " repaired itself for " << (int)amount << " points\n";
}

//GET SET

// std::string ClapTrap::getName() const{
//     return _name;
// }
