/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:00:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 11:49:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstring>
class Zombie {

public:
    std::string	name;
	
	void	announce(void);
	Zombie(std::string);
	Zombie(void);
	~Zombie(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );
void    announceHorde(Zombie *horde, int N);

#endif