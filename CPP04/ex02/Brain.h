/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:08:06 by mresch            #+#    #+#             */
/*   Updated: 2024/11/07 13:41:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
# include <cstring>
# include <string>

class Brain {
private:
    std::string ideas[100];
public:
    
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    void getIdeas() const;
    void setIdea(const std::string idea, int idx);
};

#endif