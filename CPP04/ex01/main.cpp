/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:29:05 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 11:47:13 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
int main()
{
    std::cout << "\n________________________" << std::endl;
    std::cout << "\033[1;3;33mCONSTRUTION:\033[0m\n" << std::endl;
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
    std::cout << "\n________________________" << std::endl;
    std::cout << "\033[1;3;33mSHALLOWNESS CHECK:\033[0m\n" << std::endl;
    Dog a;
    Dog b(a);

    a.getIdea("im not a dog", 0);
    b.getIdea("live laugh love", 0);
    a.utterIdea();
    b.utterIdea();

    std::cout << "\n________________________" << std::endl;
    std::cout << "\033[1;3;33mDECONSTRUCTION:\033[0m\n" << std::endl;
    for (int i = 0; i < 20; i++){
        if (animals[i])
            delete animals[i];
    }

    return 0;
}