/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:28 by mresch            #+#    #+#             */
/*   Updated: 2025/04/18 17:48:27 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PM2.hpp"

int fordjohnson(std::vector<std::vector<int> >& arr);
void printVecVec(std::vector<std::vector<int> >& v);
int main(){
    std::vector<std::vector<int> > arr;
    for (int i = 0; i < 16; i++){
        std::vector<int> a = {20 - i, i};
        arr.push_back(a);
    }

    fordjohnson(arr);
    std::cout << "After: ";
    printVecVec(arr);
    return 1;
}