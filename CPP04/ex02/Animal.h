/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:51 by mresch            #+#    #+#             */
/*   Updated: 2024/11/07 14:23:07 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>
# include <cstring>

class Animal {

public:
//CON AND DE STRUCTION
    Animal();
    virtual ~Animal();
    Animal(const Animal&);
//OPERATORS
    virtual Animal& operator=(const Animal&);
//MEMBER FUNCTIONS
    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual void utterIdea() const = 0;
    virtual void setIdea(const std::string idea, int idx) = 0;
protected:
    std::string type;
};

#endif