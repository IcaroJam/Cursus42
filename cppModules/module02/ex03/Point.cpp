/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:21:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/12 12:35:21 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Canonical form stuff
Point::Point() : _x(0), _y(0) {}

Point::Point(const float &x, const float &y) : _x(x), _y(y) {}

Point::Point(const Point &cpyFrom) { *this = cpyFrom; }

Point::~Point() {}

// Copy assignment op
Point &Point::operator =(const Point &rhs) {
	_x = rhs.getX();
	_y = rhs.getY();

	return (*this);
}

//Getters
Fixed	Point::getX() const { return _x; }

Fixed	Point::getY() const { return _y; }
