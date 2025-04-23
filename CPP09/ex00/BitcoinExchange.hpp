/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:46:22 by mresch            #+#    #+#             */
/*   Updated: 2025/04/23 14:03:11 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <stdexcept>
# include <sstream> 
# include <limits>
# include <ctime>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange& cpy);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& og);
    
    void addExchangeRate(const std::string& line);
    double getExchangeRate(const std::string& date) const;
    int readFromFile(const std::string& filename);
    double stringToDouble(const std::string& str) const;
    void processInput(const std::string& input);
    int checkDate(const std::string& date) const;
    
private:
    std::map<std::string, double> exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP