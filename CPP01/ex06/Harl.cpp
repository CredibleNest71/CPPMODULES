/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:46:48 by mresch            #+#    #+#             */
/*   Updated: 2024/06/17 12:01:26 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		(*funcs[4])(void);
void	Harl::debug( void ){
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
    std::cout << std::endl;
}
void	Harl::info( void ){
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << std::endl;
}
void	Harl::warning( void ){
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
    std::cout << "years whereas you started working here since last month.";
    std::cout << std::endl;
    
}
void	Harl::error( void ){
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

Harl::Harl(){
    this->funcs[0] = &Harl::debug;
    this->funcs[1] = &Harl::info;
    this->funcs[2] = &Harl::warning;
    this->funcs[3] = &Harl::error;
}
Harl::~Harl(){}

int     get_level(std::string level){
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++){
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void    Harl::complain( std::string level ){
    int lev = get_level(level);
    if (lev < 0)
        std::cout << "Incorrect Input" << std::endl;
    else
        (this->*(funcs[lev]))();
    return ;
}