/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:51:32 by mresch            #+#    #+#             */
/*   Updated: 2024/10/31 12:48:20 by mresch           ###   ########.fr       */
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
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	//operators
	Fixed& 	operator= (const Fixed& copy);
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif
