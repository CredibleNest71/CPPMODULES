/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:46:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 12:48:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

std::string	Weapon::getType(void){
    return (this->type);
}
void		Weapon::setType(std::string type){
    this->type = type;
    return ;
}