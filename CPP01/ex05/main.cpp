/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:35 by mresch            #+#    #+#             */
/*   Updated: 2024/06/17 11:11:27 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
    std::string input;
    Harl    harl;
    while (1){
        std::cin >> input;
        if (input == "exit")
            break ;
        harl.complain(input);
    }
    return 0;
}