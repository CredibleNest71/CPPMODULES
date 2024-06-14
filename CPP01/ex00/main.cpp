/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 11:23:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	std::string	input;
	Zombie		*zomb;
	while (1){
		std::cin >> input;
		if (input == "new")
		{
			std::cin >> input;
			zomb = newZombie(input);
			zomb->announce();
			delete zomb;
		}
		else if (input == "chump")
		{
			std::cin >> input;
			randomChump(input);
		}
		else if (input == "exit")
			break;
	}
}