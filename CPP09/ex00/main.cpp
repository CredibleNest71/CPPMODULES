/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:45 by mresch            #+#    #+#             */
/*   Updated: 2025/04/23 14:26:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

int main(int ac, char** av)
{
    BitcoinExchange exchange;
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <inputfile>" << std::endl;
        return 1;
    }
    try {
        exchange.readFromFile("data.csv");
        exchange.processInput(av[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}