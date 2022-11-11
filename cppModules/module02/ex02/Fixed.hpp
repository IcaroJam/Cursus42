/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:07:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/11 14:02:38 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	public:
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		int				toInt(void) const;
		float			toFloat(void) const;
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		Fixed &operator =(const Fixed &cpyfrom);
		bool operator >(const Fixed &rhs) const;
		bool operator <(const Fixed &rhs) const;
		bool operator >=(const Fixed &rhs) const;
		bool operator <=(const Fixed &rhs) const;
		bool operator ==(const Fixed &rhs) const;
		bool operator !=(const Fixed &rhs) const;
		Fixed operator +(const Fixed &rhs) const;
		Fixed operator -(const Fixed &rhs) const;
		Fixed operator *(const Fixed &rhs) const;
		Fixed operator /(const Fixed &rhs) const;
		Fixed &operator ++(void);
		Fixed operator ++(int);
		Fixed &operator --(void);
		Fixed operator --(int);

		Fixed();
		Fixed(const int initVal);
		Fixed(const float initVal);
		Fixed(const Fixed &cpyfrom);
		~Fixed();

	private:
		int					_fpval;
		static const int	_nfrac = 8;
};

std::ostream &operator <<(std::ostream &outstream, const Fixed &fixedFrom);

#endif
