/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:09:00 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/09 14:45:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &rhs);
	~Point();
	const Fixed &getx() const;
	const Fixed &gety() const;

private:
	Fixed _x;
	Fixed _y;
};

#endif