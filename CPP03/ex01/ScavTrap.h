/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:50:16 by mresch            #+#    #+#             */
/*   Updated: 2024/11/08 19:53:23 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include <iostream>
# include <cstring>
# include "ClapTrap.h"

class   ScavTrap : public ClapTrap
{
public:
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& cpy);
    ScavTrap();
    ~ScavTrap();

    ScavTrap& operator= (const ScavTrap& copy);
    void guardGate();
    void attack(const std::string& target);
    
};

#endif