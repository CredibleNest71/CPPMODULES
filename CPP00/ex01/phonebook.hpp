/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:27:00 by mresch            #+#    #+#             */
/*   Updated: 2024/05/29 18:12:06 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include <cstring>
# include "contact.hpp"
# include <iomanip>

class PhoneBook
{
public:

    Contact	contacts[8];
    int				idx;

    PhoneBook();

    void	add		(void);
	void	search	(void);
};

#endif
