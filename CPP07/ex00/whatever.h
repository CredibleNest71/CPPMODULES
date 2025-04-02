/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:38:11 by mresch            #+#    #+#             */
/*   Updated: 2025/01/20 15:48:40 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• swap: Swaps the values of two given arguments. Does not return anything.
• min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
• max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.*/


#ifndef WHATEVER_H
# define WHATEVER_H
# include <iostream>
# include <cstring>

template <typename T> 
void swap(T& a, T& b);

template <typename T> 
T min(T a, T b);

template <typename T> 
T max(T a, T b);



#endif