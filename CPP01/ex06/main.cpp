/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:35 by mresch            #+#    #+#             */
/*   Updated: 2024/10/21 13:34:53 by mresch           ###   ########.fr       */
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

void filtered(Harl &harl, std::string input){
    int idx;
    idx = get_idx(&input[0]);
    switch (idx) {
        case 0:
            harl.complain("DEBUG");
            idx++;
        case 1:
            harl.complain("INFO");
            idx++;
        case 2:
            harl.complain("WARNING");
            idx++;
        case 3:
            harl.complain("ERROR");
            idx++;
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

int check_input(int ac, char **av, int *filter){
    if (ac > 2){
        std::cout << "too many Arguments" << std::endl;
        return (1);
    }
    if (ac == 1){
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    else
        *filter = get_idx(av[1]);
    return (0);
}

int main(int ac, char **av){
    int     filter;
    Harl    harl;
    if (check_input(ac, av, &filter))
        return (1);
    filtered(harl, av[1]);
    return 0;
}