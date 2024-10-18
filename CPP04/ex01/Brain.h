/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:08:06 by mresch            #+#    #+#             */
/*   Updated: 2024/10/18 15:37:12 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
# include <cstring>

class Brain {
private:
    std::string ideas[100];
public:
    
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain operator=(const Brain& other);
};

#endif