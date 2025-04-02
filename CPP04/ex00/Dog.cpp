#include "Dog.h"

Dog::Dog() : Animal() {
    type = "Dog";
}
Dog::~Dog() {
    std::cout << "DeDogstructor was called" << std::endl;
}
Dog::Dog(const Dog& goodboy) : Animal(goodboy){
    *this = goodboy;
}
Dog& Dog::operator=(const Dog& goodboy){
    (void) goodboy;
    return *this;
}

void Dog::makeSound()const{
    std::cout << "barf" << std::endl;
}
