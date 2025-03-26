/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:07 by mresch            #+#    #+#             */
/*   Updated: 2025/03/25 11:53:44 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.h"
template<typename T>
Array<T>::Array(){
    arr = new T[0];
    sz = 0;
}
template<typename T>
Array<T>::Array(unsigned int n){
    arr = new T[n]();
    sz = n;
}

template<typename T>
Array<T>::~Array(){
    delete[] arr;
}

template<typename T>
Array<T>::Array(Array<T>& copy){
    arr = NULL;
    *this = copy;
}
template<typename T>
size_t Array<T>::size() const{
    return sz;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>&copy){
    if (this->arr != NULL)
        delete arr;
    this->sz = copy.sz;
    this->arr = new T[sz];
    for (size_t i = 0; i < sz; i++){
        arr[i] = copy.arr[i];
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t n) const{
    if (n >= sz)
        throw std::exception();
    return arr[n];
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arry){
    for (size_t i = 0; i < arry.size(); i++){
        os << arry[i];
    }
    return os;
}