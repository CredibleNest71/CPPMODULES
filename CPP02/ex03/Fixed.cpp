/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:01:44 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 16:17:58 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    //std::cout << "Default constructor called" << std::endl;
    this->val = 0;
}

Fixed::Fixed(const int n){
    //std::cout << "Int constructor called" << std::endl;
    this->val = n << this->frac_bits;
}

Fixed::Fixed(const float f){
    //std::cout << "Float constructor called" << std::endl;
	int	fac = 1;
	for (int i = 0; i < this->frac_bits; i++)
		fac *= 2;
	this->val = f * fac;
}

Fixed::Fixed(const Fixed& copy){
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(){
    //std::cout << "Destructor called" << std::endl;
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
int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->val;
}
void Fixed::setRawBits( int const raw ){
    this->val = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num){
	out << num.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& copy){
    //std::cout << "Copy assignment operator called" << std::endl;
    this->val = copy.val;
    return *this;
}
bool Fixed::operator< (const Fixed& other)const{
    bool ret = ((this->val < other.val) ? true : false);
    return ret;
}
bool Fixed::operator> (const Fixed& other)const{
    bool ret = ((this->val > other.val) ? true : false);
    return ret;
}
bool Fixed::operator<= (const Fixed& other)const{
    return ((this->val <= other.val) ? true : false);
}
bool Fixed::operator>= (const Fixed& other)const{
    return ((this->val >= other.val) ? true : false);
}
bool Fixed::operator== (const Fixed& other)const{
    return ((this->val == other.val) ? true : false);
}
bool Fixed::operator!= (const Fixed& other)const{
    return ((this->val != other.val) ? true : false);
}
Fixed Fixed::operator+ (const Fixed& other)const{
    Fixed ret;
    ret.setRawBits(this->val + other.val);
    return ret;
}
Fixed Fixed::operator- (const Fixed& other)const{
    Fixed ret;
    ret.setRawBits(this->val - other.val);
    return ret;
}
Fixed Fixed::operator* (const Fixed& other)const{
    Fixed   ret;
    ret.val = (this->val * other.val) / 256;
    return ret;
}
Fixed Fixed::operator/ (const Fixed& other)const{
    Fixed   ret;
    ret.val = (this->val / other.val) * 256;
    return ret;
}

Fixed& Fixed::operator++ (void){
    this->val += 1;
    return *this;
}
Fixed Fixed::operator++ (int){
    Fixed old;
    old.val = this->val;
    this->val += 1;
    return old;
}
Fixed& Fixed::operator-- (void){
    this->val -= 1;
    return *this;
}
Fixed Fixed::operator-- (int){
    Fixed old;
    old.val = this->val;
    this->val -= 1;
    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return a;
    return b;
}
