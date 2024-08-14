/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:51:32 by mresch            #+#    #+#             */
/*   Updated: 2024/08/14 15:41:21 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
private:
    int					val;
	static const int	frac_bits = 8;
public:
	//***structors
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	~Fixed();
	//memberfuncs
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	//operators
	Fixed& operator= (const Fixed& copy);
	bool operator< (const Fixed& other)const;
	bool operator> (const Fixed& other)const;
	bool operator<= (const Fixed& other)const;
	bool operator>= (const Fixed& other)const;
	bool operator== (const Fixed& other)const;
	bool operator!= (const Fixed& other)const;
	Fixed operator+ (const Fixed& other)const;
	Fixed operator- (const Fixed& other)const;
	Fixed operator* (const Fixed& other)const;
	Fixed operator/ (const Fixed& other)const;
	Fixed& operator++ (void);
	Fixed operator++ (int);
	Fixed& operator-- (void);
	Fixed operator-- (int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif
