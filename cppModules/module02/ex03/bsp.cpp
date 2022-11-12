/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:32:07 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/12 12:44:48 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static Fixed	area(const Point &A, const Point &B, const Point &C) {
	Fixed	areaVal, half(0.5f);
	// Using the "half determinant method":
	//             | x1 y1 1 |
	//Area = 0.5 * | x2 y2 1 |
	//             | x3 y3 1 |
	areaVal = half * (((A.getX() - C.getX()) * (B.getY() - C.getY())) 
				- ((B.getX() - C.getX()) * (A.getY() - C.getY())));
	areaVal.setRawBits(abs(areaVal.getRawBits()));
	return (areaVal);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
	Fixed	areaTotal, area1, area2, area3;

	areaTotal = area(a, b, c);
	area1 = area(a, b, point);
	area2 = area(b, c, point);
	area3 = area(c, a, point);
	//std::cout << areaTotal << ", " << area1 << ", " << area2 << ", " << area3 << std::endl;
	return (area1.getRawBits() && area2.getRawBits() && area3.getRawBits() && areaTotal == area1 + area2 + area3);
}
