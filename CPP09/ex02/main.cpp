/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:28 by mresch            #+#    #+#             */
/*   Updated: 2025/04/23 12:41:54 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PM.hpp"
#include <ctime>

// int fordjohnson(std::vector<std::vector<int> >& arr);
//void printVecVec(std::vector<std::vector<int> >& v);
int global = 0;

int stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int value;
    iss >> value;

    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Error: Invalid Int value: " + str);
    }
    return value;
}

int main(int ac, char **av) {
    
    std::vector<std::vector<int> > arr;
    std::deque<std::deque<int> > arrD;
    if (ac >= 2){
        for (int i = 1; i < ac; i++){
            int num;
            try {
                if (std::string(av[i]).find_first_not_of("-0123456789") != std::string::npos) {
                    throw std::invalid_argument("Error: Not a number: " + std::string(av[i]));
                }
                num = stringToInt(av[i]);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                return 1;
            }
            if (num < 0){
                std::cerr << "Error: negative number: " << num << std::endl;
                return 1;
            }
            arr.push_back(std::vector<int>(1, num));
            arrD.push_back(std::deque<int>(1, num));
        }
    }
    else
    {
        std::cout << "Please provide a range of numbers to sort" << std::endl;
        return 1;
    }

    std::clock_t startV = std::clock();
    fordjohnson(arr);
    int compV = global;
    global = 0;
    std::clock_t endV = std::clock();
    double elapsed_time_vector = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
    

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