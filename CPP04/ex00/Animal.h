/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:51 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 13:16:27 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>
# include <cstring>

class Animal {
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal&);

    Animal operator=(const Animal&);

    std::string getType() const;
    virtual void makeSound() const;
    
protected:
    std::string type;
};

#endif