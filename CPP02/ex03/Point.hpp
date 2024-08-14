/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:25:23 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 16:50:47 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"
class Point {
private:
    const Fixed	x;
    const Fixed	y;
public:
	Point();
	Point(const Point& copy);
	Point(const float x, const float y);
	~Point();
	
	Point& operator=(const Point& copy);

	const Fixed getX(void) const;
	const Fixed getY(void) const;
};

#endif