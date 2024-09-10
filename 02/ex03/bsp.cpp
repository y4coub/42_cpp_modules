/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:09:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/09 14:55:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const &a, Point const &b, Point const &c)
{
	// Calculate area of triangle ABC using Shoelace formula
	return ((a.getx() * (b.gety() - c.gety()) +
			 b.getx() * (c.gety() - a.gety()) +
			 c.getx() * (a.gety() - b.gety())) /
			Fixed(2.0f))
		.abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate area of triangle ABC
	Fixed areaABC = area(a, b, c);

	// Calculate areas of three smaller triangles
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);
	Fixed areaPAB = area(point, a, b);

	// Check if point is inside the triangle
	return (areaABC == areaPBC + areaPCA + areaPAB);
}