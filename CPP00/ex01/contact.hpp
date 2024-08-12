/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:28:25 by mresch            #+#    #+#             */
/*   Updated: 2024/06/11 16:20:51 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstring>
#include "contact.hpp"

class Contact
{
// INFO
public:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string telnr;
    std::string secret;
    Contact();
};
#endif