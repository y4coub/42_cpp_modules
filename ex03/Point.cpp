/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:09:25 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/09 14:45:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
	}
	return *this;
}

const Fixed &Point::getx() const
{
	return _x;
}

const Fixed &Point::gety() const
{
	return _y;
}

Point::~Point()
{
}
