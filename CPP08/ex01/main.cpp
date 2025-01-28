/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:05:22 by mresch            #+#    #+#             */
/*   Updated: 2025/01/28 15:50:30 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

int main()
{
    std::cout << "SUBJECT TEST" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp << std::endl;
    
    std::cout << "ADD 100 TEST" << std::endl;
    Span span = Span(100);
    for (int i = 0; i < 100; i++){
        span.addNumber(i * 2);
    }
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    std::cout << span << std::endl;


    std::cout << "ADD_RANGE TEST" << std::endl;
    Span range = Span(103);
    std::vector<int> vec;
    vec.push_back(101010);
    vec.push_back(1);
    for (int i = 0; i < 100; i++){
        vec.push_back(i * 2);
    }
    range.addRange(vec.begin(), vec.end());
    std::cout << range.shortestSpan() << std::endl;
    std::cout << range.longestSpan() << std::endl;
    std::cout << range << std::endl;

    return 0;
}