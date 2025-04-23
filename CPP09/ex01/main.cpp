/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:05:36 by mresch            #+#    #+#             */
/*   Updated: 2025/04/23 12:54:23 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    (void)ac;
    long long int result;
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    std::string input(av[1]);
    RPN rpn;
    try {
        rpn.parse(av[1]);
        result = rpn.calculate();
        std::cout << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}