/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:05:22 by mresch            #+#    #+#             */
/*   Updated: 2025/03/27 15:13:06 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

int main()
{
    std::cout << "\033[33m" << "SUBJECT TEST" << "\033[0m" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    //std::cout << "content:" << sp << std::endl;
    
    std::cout << "\033[33m" << "ADD 100 TEST" << "\033[0m" << std::endl;
    Span span = Span(100);
    for (int i = 0; i < 100; i++){
        span.addNumber(i * 2);
    }
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
   // //std::cout << span << std::endl;


    std::cout << "\033[33m" << "ADD_RANGE TEST 10 000" << "\033[0m" << std::endl;
    Span range = Span(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++){
        vec.push_back(i * 2);
    }
    range.addRange(vec.begin(), vec.end());
    std::cout << range.shortestSpan() << std::endl;
    std::cout << range.longestSpan() << std::endl;
    //std::cout << range << std::endl;

    return 0;
}