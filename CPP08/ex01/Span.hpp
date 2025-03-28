/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:04:59 by mresch            #+#    #+#             */
/*   Updated: 2025/03/24 13:50:16 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
*/

#ifndef SPAN_H
# define SPAN_H
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
class Span {
private:
    std::vector<int>    v;
    unsigned int        N;
public:
    Span();
    Span(unsigned int maxSize);
    ~Span();
    Span(const Span&);

    
    template <typename It>
    void    addRange(It begin, It end){
        size_t num = static_cast<size_t>(std::distance(begin, end));
        if (v.size() + num > N)
            throw OutOfRangeException();
        v.insert(v.end(), begin, end);
    }
    
    //METHODS
    int     shortestSpan();
    int     longestSpan();
    void    addNumber(int);
    std::vector<int>    getV() const;

    Span& operator=(const Span& copy);

    class OutOfRangeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const Span& span);
#endif