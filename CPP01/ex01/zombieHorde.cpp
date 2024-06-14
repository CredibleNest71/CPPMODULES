/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:30:47 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 11:51:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie  *horde = new Zombie[N];
    for (int i = 0; i < N; i++){
        new (&horde[i]) Zombie(name);
    }
    return (horde);
}

void    announceHorde(Zombie *horde, int N){
    for (int i = 0; i < N; i++){
        horde[i].announce();
    }
}