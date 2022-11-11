/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:07:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/11 12:10:41 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class	Fixed {
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		Fixed();
		Fixed(const int initVal);
		Fixed(const float initVal);
		Fixed(const Fixed &cpyfrom);
		Fixed &operator=(const Fixed &cpyfrom);
		~Fixed();

	private:
		int					_fpval;
		static const int	_nfrac = 8;
};

std::ostream &operator <<(std::ostream &outstream, const Fixed &fixedFrom);

#endif
