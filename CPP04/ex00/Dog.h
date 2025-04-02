/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:32 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 10:37:07 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include <iostream>
# include <cstring>
# include "Animal.h"

class Dog : public Animal{

public:
    Dog();
    ~Dog();
    Dog(const Dog& goodboy);

    Dog& operator=(const Dog& goodboy);

    void makeSound()const;
};

#endif
