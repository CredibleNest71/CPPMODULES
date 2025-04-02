/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:55 by mresch            #+#    #+#             */
/*   Updated: 2024/11/13 13:02:52 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int main(){
    ClapTrap a("Hubert");
    ClapTrap b("Fred");
    a = b;
    ClapTrap df(a);
    a.attack("Jakob");
    b.beRepaired(10);
    b.takeDamage(15);

    ScavTrap c("Nathanael");
    ScavTrap d(c);
    d.takeDamage(300);
    c.attack("Fred");
    c.guardGate();
    
    a.attack("MOOOOOOOO");
    c.attack("MOOOOOOOO");

    return (0);
}