/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:00 by mresch            #+#    #+#             */
/*   Updated: 2024/11/08 19:55:05 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <cstring>

class   ClapTrap
{
protected:
    std::string     _name;
    unsigned int    _hp;
    unsigned int    _energy;
    unsigned int    _dmg;
public:
    ClapTrap(std::string name);
    ClapTrap();
    ClapTrap(const ClapTrap& cpy);
    ~ClapTrap();
    ClapTrap& operator= (const ClapTrap&);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // std::string     getName() const;
    // unsigned int    getHp() const;
    // unsigned int    getEnergy() const;
    // unsigned int    getDmg() const;

    // void            setName();
    // void            setHp(unsigned int);
    // void            setEnergy(unsigned int);
    // void            setDmg();
};

#endif