/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:42:50 by mresch            #+#    #+#             */
/*   Updated: 2025/01/20 15:45:24 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.h"

/*
• swap: Swaps the values of two given arguments. Does not return anything.
• min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
• max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.*/

template <typename T> 
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
template <typename T> 
T min(T a, T b){
    if (a < b)
        return a;
    return b;
}
template <typename T> 
T max(T a, T b){
    if (a > b)
        return a;
    return b;
}

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}