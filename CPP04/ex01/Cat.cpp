#include "Cat.h"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain;
}
Cat::~Cat() {
    delete brain;
    std::cout << "DeCatstructor was called" << std::endl;
}
Cat::Cat(const Cat& goodboy) : Animal(goodboy){
    brain = NULL;
    *this = goodboy;
}
Cat& Cat::operator=(const Cat& goodboy){
    if (this == &goodboy)
        return *this;
    if (brain != NULL)
        delete brain;
    brain = new Brain(*goodboy.brain);
    return *this;
}

void Cat::makeSound()const{
    std::cout << "miau" << std::endl;
}
void Cat::utterIdea() const{
    brain->getIdeas();
}
void Cat::getIdea(const std::string idea, int idx){
    brain->setIdea(idea, idx);
}

