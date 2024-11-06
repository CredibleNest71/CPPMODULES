/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:29:05 by mresch            #+#    #+#             */
/*   Updated: 2024/11/06 13:24:17 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
int main()
{
    Dog*  animals[20];
    for (int i = 0; i < 20; i++){
        animals[i] = new Dog;
    }
    for (int i = 0; i < 20; i++){
        animals[i]->makeSound();
    }

    //check SHALLOWNESS
    std::cout << "\n\n" << std::endl;
    animals[0]->utterIdea();
    animals[1] = animals[0];
    animals[0]->getIdea("im not a dog!");
    animals[0]->utterIdea();
    animals[1]->utterIdea();
    std::cout << "\n\n" << std::endl;

    for (int i = 0; i < 20; i++){
        delete animals[i];
    }

    return 0;
}