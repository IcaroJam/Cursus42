/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:07:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/08 12:29:55 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed();
		Fixed(const Fixed &cpyfrom);
		Fixed &operator=(const Fixed &cpyfrom);
		~Fixed();

	private:
		int					_fpval;
		static const int	_nfrac = 8;
};

#endif
