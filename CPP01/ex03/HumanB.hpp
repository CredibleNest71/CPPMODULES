/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:25:35 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 16:24:05 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <cstring>
# include "Weapon.hpp"

class   HumanB{
private:
    std::string name;
	Weapon	    *weapon;

public:


	HumanB(std::string name);
	~HumanB(void);
    void	setWeapon(Weapon& weapon);

	void	attack(void) const;
};

#endif