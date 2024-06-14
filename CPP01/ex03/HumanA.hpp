/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:25:35 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 13:02:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <cstring>
# include "Weapon.hpp"

class   HumanA{

public:
	Weapon&		weapon;
	std::string	name;

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;
};

#endif