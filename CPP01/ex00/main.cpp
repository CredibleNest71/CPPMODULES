/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 13:19:25 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	std::string	input;
	Zombie		*zomb;
	std::cout << "new/chump/exit" << std::endl;
	while (1){
		std::cin >> input;
		if (std::cin.eof()){
			std::cout << "End of input (EOF) detected." << std::endl;
			break;
		}
		if (input == "new")
		{
			zomb = newZombie(input);
			zomb->announce();
			delete zomb;
		}
		else if (input == "chump")
		{
			randomChump(input);
		}
		else if (input == "exit")
			break;
	}
	return (0);
}