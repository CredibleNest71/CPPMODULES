/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:30:47 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 16:19:51 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (N <= 0 || name.empty()){
        std::cout << "invalid number of Zombies, must be at least 1 Zombie.... with a name!" << std::endl;
        return NULL;
    }
    Zombie  *horde = new Zombie[N];
    for (int i = 0; i < N; i++){
        horde[i].setName(name);
    }
    return (horde);
}

void    announceHorde(Zombie *horde, int N){
    if (horde == NULL)
        return ;
    for (int i = 0; i < N; i++){
        horde[i].announce();
    }
}