/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:50:54 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/08 17:27:44 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractional_bits = 8;
};

#endif
