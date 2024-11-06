/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:29:05 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 15:15:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
int main()
{
    Animal*  animals[20];
    for (int i = 0; i < 20; i++){
        if (i % 2){
            animals[i] = new Dog;
        }
        else
            animals[i] = new Cat;
    }
    for (int i = 0; i < 20; i++){
        animals[i]->makeSound();
    }

    //check SHALLOWNESS
    std::cout << "\n\n" << std::endl;
    Animal a();
    Animal a();
    a.getIdea("im not a dog");
    std::cout << "\n\n" << std::endl;

    for (int i = 0; i < 20; i++){
        if (animals[i])
            delete animals[i];
    }

    return 0;
}