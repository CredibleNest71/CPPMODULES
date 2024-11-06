/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:30:17 by codespace         #+#    #+#             */
/*   Updated: 2024/10/24 16:17:04 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int n = 5;
    Zombie  *horde = zombieHorde(n, "Evelyn");
    announceHorde(horde, n);
    if (horde != NULL)
        delete[] horde;
    return 0;
}
