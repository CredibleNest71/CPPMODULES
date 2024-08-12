/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:42:33 by mresch            #+#    #+#             */
/*   Updated: 2024/06/12 11:42:51 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int main(){
    PhoneBook   ph;
    std::string input;
    while (1){
        std::cin >> input;
        if (input == "ADD")
            ph.add();
        else if (input == "SEARCH")
            ph.search();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Enter command (ADD/SEARCH/EXIT)" << std::endl;
    }
    return 0;
}