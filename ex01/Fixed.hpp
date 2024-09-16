/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:50:54 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/16 16:03:12 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _value;
	static const int _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
