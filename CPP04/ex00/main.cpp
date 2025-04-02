/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:29:05 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 11:26:23 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
int main()
{
    std::cout << "____________________" << std::endl;
    std::cout << "\033[1;3;33mCONSTRUCTION: \033[0m\n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    
    std::cout << "____________________" << std::endl;
    std::cout << "\033[1;3;33mMAKE SOUND: \033[0m\n" << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    const WrongAnimal* w = new WrongCat();
    w->makeSound();
    
    std::cout << "____________________" << std::endl;
    std::cout << "\033[1;3;33mDESTRUCTION: \033[0m\n" << std::endl;
    delete w;
    delete j;
    delete i;
    delete meta;
    return 0;
}