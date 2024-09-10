/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:50:34 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/09 14:51:32 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printResult(const char *testName, bool result)
{
	std::cout << testName << ": " << (result ? "Inside" : "Outside") << std::endl;
}

int main()
{
	// Define the triangle
	Point a(0.0f, 0.0f);
	Point b(10.0f, 30.0f);
	Point c(20.0f, 0.0f);

	// Test cases
	Point inside(10.0f, 15.0f);
	Point outside(30.0f, 15.0f);
	Point onEdge(10.0f, 0.0f);
	Point onVertex(0.0f, 0.0f);
	Point justOutside(9.99f, 29.99f);

	// Run tests
	printResult("Point inside triangle", bsp(a, b, c, inside));
	printResult("Point outside triangle", bsp(a, b, c, outside));
	printResult("Point just outside triangle", bsp(a, b, c, justOutside));

	return 0;
}