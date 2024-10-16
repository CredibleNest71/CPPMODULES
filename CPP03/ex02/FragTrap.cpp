/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:52:10 by mresch            #+#    #+#             */
/*   Updated: 2024/10/14 15:25:17 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "ClapTrap.h"

void FragTrap::highFivesGuys(void){
    std::cout << "\"High five?!\" FragTrap" << _name << " asks calmly" << std::endl ;
}

FragTrap::FragTrap() : ClapTrap(){
    _name = "NONAME";
    _hp = 100;
    _energy = 100;
    _dmg = 30;
    std::cout << "it's a FragTRAP!! :O" << std::endl ;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
    _hp = 100;
    _energy = 50;
    _dmg = 20;
    std::cout << "it's a FragTRAP!! :O" << std::endl ;
}

FragTrap::~FragTrap(){
    std::cout << "Fragtrap " << _name << " says  \"BYE!\"" << std::endl ;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(){
    *this = cpy;
    std::cout << "FragTrap was copied :)" << std::endl ;
}

FragTrap& FragTrap::operator= (const FragTrap& copy) {
    _name = copy._name;
    _hp = copy._hp;
    _energy = copy._energy;
    _dmg = copy._dmg;
    std::cout << "Frag Assignement was used" << std::endl ;
    return *this;
}