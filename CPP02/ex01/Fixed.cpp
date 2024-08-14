/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:01:44 by mresch            #+#    #+#             */
/*   Updated: 2024/08/12 18:06:47 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->val = 0;
}

Fixed::Fixed(const int n){
    std::cout << "Int constructor called" << std::endl;
    this->val = n << this->frac_bits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
	int	fac = 1;
	for (int i = 0; i < this->frac_bits; i++)
		fac *= 2;
	this->val = f * fac;
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
	for (int i = 0; i < this->frac_bits; i++)
		fac *= 2;
	
	return (float) this->val / fac;
}

int Fixed::toInt( void ) const{
	return val >> this->frac_bits;
}
Fixed& Fixed::operator=(const Fixed& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    this->val = copy.val;
    return *this;
}
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->val;
}
void Fixed::setRawBits( int const raw ){
    this->val = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num){
	out << num.toFloat();
	return out;
}
