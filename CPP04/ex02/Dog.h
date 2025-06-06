/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:32 by mresch            #+#    #+#             */
/*   Updated: 2024/11/07 14:23:19 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include <iostream>
# include <cstring>
# include "Animal.h"
# include "Brain.h"

class Dog : public Animal{
private:
    Brain*  brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog& goodboy);

    Dog& operator=(const Dog& goodboy);

    void makeSound()const;
    void utterIdea() const;
    void setIdea(const std::string idea, int idx);

};

#endif
