/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:00:50 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 16:18:43 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstring>
class Zombie {
private:
    std::string	name;
public:
	void	announce(void);
	Zombie(std::string);
	Zombie(void);
	~Zombie(void);
	void	setName(const std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );
void    announceHorde(Zombie *horde, int N);

#endif