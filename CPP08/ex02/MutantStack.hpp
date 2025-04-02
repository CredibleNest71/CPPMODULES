/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:04:59 by mresch            #+#    #+#             */
/*   Updated: 2025/03/27 15:16:55 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& cpy);
    MutantStack<T>& operator=(const MutantStack<T>& og);

    typedef typename std::stack<T>::container_type cont;
    typedef typename cont::iterator iterator;
    typedef typename cont::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "MutantStack.tpp"

#endif