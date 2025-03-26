/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:09:07 by mresch            #+#    #+#             */
/*   Updated: 2025/01/10 16:35:17 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"

Base * generate(void){
    switch (rand() % 3){
        case 0: 
            return new A;
        case 1: 
            return new B;
        case 2: 
            return new C;
    }
    return NULL;
}
void identify(Base* p){
    if (dynamic_cast<A*>(p)){
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)){
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)){
        std::cout << "C" << std::endl;
    }
    else std::cerr << "could not identify" << std::endl;
}
void identify(Base& p){
    try {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...){}
    try {
        B& b= dynamic_cast<B&>(p);
        (void) b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...){}
    try {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...){}
    std::cerr << "could not identify" << std::endl;
}

int main (){
    std::srand(std::time(0)); //set random seed.

    Base *p1 = new Base;
    identify(p1);
    identify(*p1);

    Base *p2 = generate();
    identify(p2);
    identify(*p2);

    Base *p3 = generate();
    identify(p3);
    identify(*p3);

    Base *p4 = generate();
    identify(p4);
    identify(*p4);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}