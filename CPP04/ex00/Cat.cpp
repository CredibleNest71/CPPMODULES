#include "Cat.h"

Cat::Cat() : Animal() {
    type = "Cat";
}
Cat::~Cat() {
    std::cout << "DeCatstructor was called" << std::endl;
}
Cat::Cat(const Cat& goodboy) : Animal(goodboy){
    *this = goodboy;
}
Cat& Cat::operator=(const Cat& goodboy){
    (void) goodboy;
    return *this;
}

void Cat::makeSound()const{
    std::cout << "miau" << std::endl;
}
