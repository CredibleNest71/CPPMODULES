/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:51:32 by mresch            #+#    #+#             */
/*   Updated: 2024/08/12 15:11:49 by mresch           ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	Fixed& operator= (const Fixed& copy);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif