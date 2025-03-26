/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:55:33 by mresch            #+#    #+#             */
/*   Updated: 2025/03/25 11:50:42 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

template<typename T>
void    iter(T *address, size_t idx, void (*func)(T&)){
    for (size_t i = 0; i < idx; i++){
        func(address[i]);
    }
}

template <typename T>
void print(T& t){
    std::cout << t << std::endl;
}

template <typename T>
void add(T& t){
    t++;
}

int main(){
    // 3 different arrays
    int arr[2] = {0,1};
    char carr[4] = {'i','o','u','2'};
    std::string sarr[2] = {"hey", "bye"};
    
    std::cout << "int array" << std::endl;
    iter(arr, 2, print);
    
    std::cout << "int array add 1" << std::endl;
    iter(arr, 2, add);
    iter(arr, 2, print);
    
    std::cout << "char array" << std::endl;
    iter(carr, 4, print);
    
    std::cout << "string array" << std::endl;
    iter(sarr, 2, print);

    return 0;
}
