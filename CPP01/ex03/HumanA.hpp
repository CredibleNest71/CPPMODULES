/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:25:35 by codespace         #+#    #+#             */
/*   Updated: 2024/10/18 16:24:02 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <cstring>
# include "Weapon.hpp"

class   HumanA{
private:
	std::string	name;
	Weapon&		weapon;

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;
};

#endif