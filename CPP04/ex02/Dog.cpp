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
    if (brain != NULL)
        delete brain;
    if (this == &goodboy)
        return *this;
    type = goodboy.type;
    brain = new Brain(*goodboy.brain);
    return *this;
}

void Dog::makeSound()const{
    std::cout << "barf" << std::endl;
}
void Dog::utterIdea() const{
    brain->getIdeas();
}
void Dog::setIdea(const std::string idea, int idx){
    brain->setIdea(idea, idx);
}
