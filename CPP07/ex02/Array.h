/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:46:37 by mresch            #+#    #+#             */
/*   Updated: 2025/01/20 17:39:56 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdio.h>
# include <iostream>
# include <stdexcept>

template<typename T>
class Array{
private:
    T* arr;
    size_t sz;
public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(Array&);

    size_t size() const;
    Array& operator=(const Array&);
    T& operator[](size_t) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);
#endif