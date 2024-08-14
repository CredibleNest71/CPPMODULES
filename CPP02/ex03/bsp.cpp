/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:47:30 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 17:28:16 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed   denom;
    Fixed   lambda1;
    Fixed   lambda2;
    Fixed   lambda3;
    denom = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());
    std::cout << denom << b.getY();
    if (!denom.getRawBits())
        return (false);
    lambda1 = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denom;
    lambda2 = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denom;
    lambda3 = Fixed(1) - lambda1 - lambda2;
    return (lambda1 >= 0) && (lambda1 <= 1) && (lambda2 >= 0) && (lambda2 <= 1) && (lambda3 >= 0) && (lambda3 <= 1);
}
