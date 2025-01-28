/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:04:57 by mresch            #+#    #+#             */
/*   Updated: 2025/01/28 15:47:35 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"    
    
    Span::Span(){
        N = 0;
    }
    Span::Span(unsigned int maxSize) : N(maxSize) {}
    
    Span::~Span(){}
    
    Span::Span(const Span& copy){
        *this = copy;
    }

    void    Span::addNumber(int n){
        if (v.size() + 1 > N)
           throw OutOfRangeException();
        v.push_back(n);
    }

    int     Span::shortestSpan(){
        if (v.size() < 2)
           throw OutOfRangeException();
        std::vector<int> temp = v;
        std::sort(temp.begin(), temp.end());
        int min = temp[1] - temp[0];
        for (size_t i = 1; i < v.size(); i++){
            if (temp[i] - temp[i - 1] < min)
                min = temp[i] - temp[i - 1];
        }
        return min;
    }

    int     Span::longestSpan(){
        if (v.size() < 2)
           throw OutOfRangeException();
        std::vector<int> temp = v;
        std::sort(temp.begin(), temp.end());
        int max = temp.back() - temp[0];
        return max;
    }

    std::vector<int>    Span::getV() const{
        return v;
    }
    Span& Span::operator=(const Span& copy){
    if (this != &copy) {
        N = copy.N;
        v = copy.v;
    }
    return *this;
    }

    const char* Span::OutOfRangeException::what() const throw(){
        return "Out of Range";
    }

    std::ostream& operator<<(std::ostream& os, const Span& span){
        size_t k = span.getV().size();
        for (size_t i = 0; i < k; i++)
            os << span.getV()[i] << "\n";
        os << std::endl;
        return os;
    }
