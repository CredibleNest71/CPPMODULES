/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:45 by mresch            #+#    #+#             */
/*   Updated: 2025/03/27 16:33:43 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

int main(int ac, char** av)
{
    BitcoinExchange exchange;
    if (exchange.readFromFile("data.csv"))
    {
        std::cerr << "Failed to read from data.csv" << std::endl;
        return 1;
    }
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <date>" << std::endl;
        return 1;
    }
    exchange.processInput(av[1]);
    return 0;
}