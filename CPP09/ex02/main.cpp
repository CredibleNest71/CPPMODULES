/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:28 by mresch            #+#    #+#             */
/*   Updated: 2025/04/22 16:43:05 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PM.hpp"
#include <ctime>

// int fordjohnson(std::vector<std::vector<int> >& arr);
//void printVecVec(std::vector<std::vector<int> >& v);
template<typename NestedContainer>
bool sorted(NestedContainer& v){
    int curr = 0;
    bool ret = true;
    for (size_t i = 0; i < v.size(); i++){
        if (v[i].front() < curr){
            std::cout << "Not sorted: " << v[i].front() << " < " << curr << std::endl;
            ret = false;
        }
        curr = v[i].front();
    }
    if (ret)
        std::cout << "Sorted!" << std::endl;
    return ret;
}

int global = 0;

int main(int ac, char **av) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    std::vector<std::vector<int> > arr;
    std::deque<std::deque<int> > arrD;
    int amount = 16;
    if (ac >= 2)
        amount = atoi(av[1]);
    if (amount < 0){
        std::cerr << "Error: Negative number: " << amount << std::endl;
        return 1;
    }
    for (int i = 0; i < amount; i++){
        int num = std::rand() % amount * 2;
        std::vector<int> temp;
        temp.push_back(num);
        std::deque<int> tempD;
        tempD.push_back(num);
        arr.push_back(temp);
        arrD.push_back(tempD);
    }

    std::clock_t startV = std::clock();
    fordjohnson(arr);
    int compV = global;
    global = 0;
    std::clock_t endV = std::clock();
    double elapsed_time_vector = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
    
    // Measure execution time of fordjohnson with DEQUE
    std::clock_t startD = std::clock();
    fordjohnson(arrD);
    int compD = global;
    std::clock_t endD = std::clock();
    double elapsed_time_deque = static_cast<double>(endD - startD) / CLOCKS_PER_SEC;
    
    std::cout << "After: " << std::endl;
    printVecVec(arr);
    sorted(arr);
    std::cout << "Time to proess a range of " << arr.size() << " elements with std::vector : " << elapsed_time_vector << " seconds, with " << compV << " comparisons" << std::endl;
    std::cout << "Time to process a range of " << arrD.size() << " elements with std::deque : " << elapsed_time_deque << " seconds, with " << compD << " comparisons" << std::endl;
    return 0;
}