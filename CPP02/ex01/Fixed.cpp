/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:01:44 by mresch            #+#    #+#             */
/*   Updated: 2024/10/31 12:50:04 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    val = 0;
}

Fixed::Fixed(const int n){
    std::cout << "Int constructor called" << std::endl;
    val = n << frac_bits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
	int	fac = 1;
	for (int i = 0; i < frac_bits; i++)
		fac *= 2;
	val = f * fac;
}

Fixed::Fixed(const Fixed& copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const{
	int	fac = 1;
	for (int i = 0; i < frac_bits; i++)
		fac *= 2;
	
	return (float) val / fac;
}

int Fixed::toInt( void ) const{
	return val >> frac_bits;
}
Fixed& Fixed::operator=(const Fixed& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    val = copy.val;
    return *this;
}
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return val;
}
void Fixed::setRawBits( int const raw ){
    val = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num){
	out << num.toFloat();
	return out;
}
