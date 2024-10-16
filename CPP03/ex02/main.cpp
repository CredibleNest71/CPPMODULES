/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:55 by mresch            #+#    #+#             */
/*   Updated: 2024/10/14 15:43:03 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int main(){
    ClapTrap a("Hubert");
    ClapTrap b("Fred");
    ClapTrap j;
    j.attack("someone");
    a = b;
    a.attack("Jakob");
    b.beRepaired(10);
    b.takeDamage(15);

    ScavTrap c("Nathanael");
    ScavTrap d(c);
    d.takeDamage(300);
    c.attack("Fred");
    c.guardGate();

    FragTrap e("Henning May");
    e.highFivesGuys();
    e.attack("someone");
    FragTrap f;
    f = e;

    return (0);
}