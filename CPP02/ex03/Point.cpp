/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:29:42 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 17:29:28 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(){
    (Fixed) this->x = Fixed(0);
    (Fixed) this->y = Fixed(0);
}
Point::Point(const Point& copy){
    *this = copy;
}
Point::Point(const float x, const float y){
    (Fixed) this->x = Fixed(x);
    (Fixed) this->y = Fixed(y);
}
Point::~Point(){}

Point& Point::operator=(const Point& copy){
    (Fixed) this->x = copy.x;
    (Fixed) this->x = copy.x;
    return *this;
}
const Fixed Point::getX(void)const{return this->x;}
const Fixed Point::getY(void)const{return this->y;}