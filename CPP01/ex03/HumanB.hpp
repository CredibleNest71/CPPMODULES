/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:25:35 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 13:01:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <cstring>
# include "Weapon.hpp"

class   HumanB{

public:

	Weapon	    *weapon;
    std::string name;

	HumanB(std::string name);
	~HumanB(void);
    void	setWeapon(Weapon& weapon);

	void	attack(void) const;
};

#endif