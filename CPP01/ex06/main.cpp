/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:35 by mresch            #+#    #+#             */
/*   Updated: 2024/06/17 12:33:32 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int get_idx(char *input){
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++){
        if (levels[i] == input)
            return i;
    }
    return 5;
}

void filtered(Harl &harl, int filter){
    int idx;
    std::string input;
    while (1){
        std::cin >> input;
        if (input == "exit")
            break ;
        idx = get_idx(&input[0]);
        if (idx < filter){
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;        
            continue ;
        }
        switch (idx) {
            case 0:
                harl.complain("DEBUG");
                break;
            case 1:
                harl.complain("INFO");
                break;
            case 2:
                harl.complain("WARNING");
                break;
            case 3:
                harl.complain("ERROR");
                break ;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }
}

int check_input(int ac, char **av, int *filter){
    if (ac > 2){
        std::cout << "too many Arguments" << std::endl;
        return (1);
    }
    if (ac == 1)
        *filter = 0;
    else
        *filter = get_idx(av[1]);
    return (0);
}

int main(int ac, char **av){
    int     filter;
    Harl    harl;
    if (check_input(ac, av, &filter))
        return (1);
    filtered(harl, filter);
    return 0;
}