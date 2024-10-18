/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:35 by mresch            #+#    #+#             */
/*   Updated: 2024/10/18 13:52:07 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
    std::string input;
    Harl        harl;
    while (1){
        std::cout << "Commands: [DEBUG|INFO|WARNING|ERROR|exit]" << std::endl;
        std::cin >> input;
		if (std::cin.eof()){
			std::cout << "End of input (EOF) detected." << std::endl;
			break;
		}
        if (input == "exit")
            break ;
        harl.complain(input);
    }
    return 0;
}