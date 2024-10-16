/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:55 by mresch            #+#    #+#             */
/*   Updated: 2024/10/01 15:59:56 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main(){
    ClapTrap a("Hubert");
    ClapTrap b("Fred");

    a.attack("Jakob");
    b.beRepaired(10);
    b.takeDamage(15);
    return (0);
}