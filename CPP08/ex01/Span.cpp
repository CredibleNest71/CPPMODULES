#include "Span.hpp"    
    
    Span::Span(){
        N = 0;
    }
    Span::Span(unsigned int N) : N(N) {}
    Span::~Span(){}
    Span::Span(Span& copy){
        *this = copy;
    }

    void    Span::addNumber(int n){
        //if (v.size() + 1 > N)
        //    throw exception
        v.push_back(n);
    }
    int     Span::shortestSpan(){
        //if (v.size() < 2)
        //    throw exception;
        std::vector<int> temp = v;
        std::sort(temp.begin(), temp.end());
        int min = temp[1] - temp[0];
        for (int i = 1; i < v.size(); i++){
            if (temp[i] - temp[i - 1] < min)
                min = temp[i] - temp[i - 1];
        }
    }
    int     Span::longestSpan(){
        //if (v.size() < 2)
        //    throw exception;
        std::vector<int> temp = v;
        std::sort(temp.begin(), temp.end());
        int max = temp[1] + temp[0];
        for (int i = 1; i < v.size(); i++){
            if (temp[i] + temp[i - 1] < max)
                max = temp[i] + temp[i - 1];
        }
    }

    Span& Span::operator=(const Span& copy){
        v = copy.v;
        N = copy.N;
    }