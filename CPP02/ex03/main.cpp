/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:59:07 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 17:30:33 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
Point a(0, 0);
Point b(10,10);
Point c(10, 0);
Point p(2, 3);
std::cout << b.getX();

if (bsp(a, b, c, p))
    std::cout << " is  within\n";
}
