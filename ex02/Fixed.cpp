/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:50:51 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/21 00:32:32 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		_value = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return _value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed fixed;
	long result = static_cast<long>(_value) * static_cast<long>(rhs._value);
	fixed.setRawBits(result >> _fractional_bits);
	return fixed;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	if (rhs._value == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return *this;
	}
	Fixed fixed;
	int64_t result = static_cast<int64_t>(_value) << _fractional_bits;
	result /= rhs._value;
	fixed.setRawBits(result);
	return fixed;
}

Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}
Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed::Fixed(const int value)
{
	_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractional_bits));
}

int Fixed::toInt(void) const
{
	return _value >> _fractional_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}