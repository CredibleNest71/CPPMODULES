/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:45 by mresch            #+#    #+#             */
/*   Updated: 2025/03/26 14:51:10 by mresch           ###   ########.fr       */
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
    std::ifstream request(av[1]);
    if (!request.is_open()) {
        throw std::runtime_error("Error: Unable to open file ");
    }
    std::string line;
    
    while ( std::getline(request, line)) {
        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos) {
            std::cerr << line << ": Error: Invalid exchange rate format: '|' missing" << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimiterPos - 1);
        std::string amount = line.substr(delimiterPos + 2); // +2 to skip the space
        try {
            double rate = exchange.getExchangeRate(date);
            double amountD = exchange.stringToDouble(amount);
            std::cout << date << "==> " << rate * amountD << std::endl;
        } catch (const std::exception& e) {
            std::cerr << date << ": " << e.what() << std::endl;
        }
    }
    return 0;
}