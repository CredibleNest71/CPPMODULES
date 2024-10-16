/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:00 by mresch            #+#    #+#             */
/*   Updated: 2024/10/03 13:46:36 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// First, you have to implement a class! How original!
// It will be called ClapTrap and will have the following private attributes initialized
// to the values specified in brackets:

// • Name, which is passed as parameter to a constructor
// • Hit points (10), represent the health of the ClapTrap
// • Energy points (10)
// • Attack damage (0)
// Add the following public member functions so the ClapTrap looks more realistic:
// • void attack(const std::string& target);
// • void takeDamage(unsigned int amount);
// • void beRepaired(unsigned int amount);

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.
// 5
// C++ - Module 03 Inheritance
// In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
// the angle brackets):
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
// The constructors and destructor must also display a message, so your peer-evaluators
// can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.
#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <cstring>
class   ClapTrap
{
private:
    std::string     _name;
    unsigned int    _hp = 0;
    unsigned int    _energy = 10;
    unsigned int    _dmg = 0;
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap ClapTrap::operator= (const ClapTrap& copy);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif