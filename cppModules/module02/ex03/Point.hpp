/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:02:32 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/12 12:35:37 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		

		Point();
		Point(const float &x, const float &y);
		Point(const Point &cpyFrom);
		~Point();

		Point &operator =(const Point &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif
