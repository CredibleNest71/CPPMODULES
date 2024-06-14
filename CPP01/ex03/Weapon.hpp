/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:25:35 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 12:46:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <cstring>

class   Weapon{

public:
	Weapon(std::string);
    std::string	getType(void);
    void		setType(std::string type);
private:
    std::string type;
};

#endif