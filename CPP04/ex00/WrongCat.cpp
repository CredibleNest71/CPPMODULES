#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal(){
    type = "WrongCat";
}
WrongCat::~WrongCat() {
    std::cout << "DeWrongCatstructor was called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& goodboy) : WrongAnimal(goodboy){
    *this = goodboy;
}
WrongCat WrongCat::operator=(const WrongCat& goodboy){
    if (this == &goodboy)
        return *this;
    return *this;
}

void WrongCat::makeSound()const{
    std::cout << "not miau" << std::endl;
}
