/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:50:16 by mresch            #+#    #+#             */
/*   Updated: 2024/10/14 15:17:04 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <iostream>
# include <cstring>
# include "ClapTrap.h"

class   FragTrap : public ClapTrap
{
public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& cpy);
    FragTrap();
    ~FragTrap();

    FragTrap& operator= (const FragTrap& copy);
    void highFivesGuys(void);
};

#endif