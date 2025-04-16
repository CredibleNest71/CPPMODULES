/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:03:28 by mresch            #+#    #+#             */
/*   Updated: 2025/04/16 12:55:47 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "PM.hpp"


int main(int ac, char **av) {
    PM pm;
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <input>" << std::endl;
        return 1;
    }
    std::string input = av[1];
    if (pm.readInput(input))
        return 1;

    std::cout << "Before: ";
    pm.printVector(pm._v, 5);

    // Measure execution time of fordjohnson with VECTOR
    std::clock_t startV = std::clock();
    pm.fordjohnson(pm._v);
    std::clock_t endV = std::clock();
    double elapsed_time_vector = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
    
    // Measure execution time of fordjohnson with DEQUE
    std::clock_t startD = std::clock();
    pm.fordjohnsonD(pm._d);
    std::clock_t endD = std::clock();
    double elapsed_time_deque = static_cast<double>(endD - startD) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    pm.printVector(pm._v, 5);
    std::cout << "Time to process a range of " << pm._v.size() << " elements with std::vector : " << elapsed_time_vector << " seconds" << std::endl;
    std::cout << "Time to process a range of " << pm._d.size() << " elements with std::deque : " << elapsed_time_deque << " seconds" << std::endl;



    return 0; 
}