/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:46:11 by mresch            #+#    #+#             */
/*   Updated: 2025/01/20 17:42:49 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.cpp"

int main(){

    Array<int> a;
    Array<int> b(3);
    Array<int> c(b);
    Array<std::string> d(2);
    

    b[0] = 3;
    try {
        a[4] = 5;
    }
    catch(...){
        std::cout << "IDX out of bounds" << std::endl;
    }
    d[0] = "what";
    d[1] = " this actually works!";
    std::cout << a << b << c << d << std::endl;

    return 0;
}