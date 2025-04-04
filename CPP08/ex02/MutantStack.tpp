#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& cpy){
    *this = cpy;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return this->c.begin();
}
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
    return this->c.end();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
    return this->c.begin();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
    return this->c.end();
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& og) {
    if (this != &og) {
        std::stack<T>::operator=(og); // base class assignment operator
    }
    return *this;
}