#include "Dog.h"

Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain;
}
Dog::~Dog() {
    delete brain;
    std::cout << "DeDogstructor was called" << std::endl;
}
Dog::Dog(const Dog& goodboy) : Animal(goodboy){
    brain = NULL;
    *this = goodboy;
}
Dog& Dog::operator=(const Dog& goodboy){
    if (this == &goodboy)
        return *this;
    if (brain != NULL)
        delete brain;
    brain = new Brain(*goodboy.brain);
    return *this;
}

void Dog::makeSound()const{
    std::cout << "barf" << std::endl;
}
void Dog::utterIdea() const{
    brain->getIdeas();
}
void Dog::getIdea(const std::string idea, int idx){
    brain->setIdea(idea, idx);
}
