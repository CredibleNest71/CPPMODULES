/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:37:22 by mresch            #+#    #+#             */
/*   Updated: 2024/06/17 11:09:18 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	HARL_HPP
# define	HARL_HPP
# include <string>
# include <iostream>

class Harl
{
private:
	void	(Harl::*funcs[4])(void);
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
    Harl();
    ~Harl();
	void complain( std::string level );
};

#endif