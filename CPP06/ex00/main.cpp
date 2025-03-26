/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:20:31 by mresch            #+#    #+#             */
/*   Updated: 2025/01/10 14:03:53 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Incorrect amount of arguments" << std::endl;
        return 1;
    }
    std::string val = av[1];
    ScalarConverter::convert(val);

    return 0;
}