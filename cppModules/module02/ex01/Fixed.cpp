/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/11 12:45:35 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpval(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int initVal) : _fpval(initVal << _nfrac) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float initVal) : _fpval((int)roundf(initVal * (1 << _nfrac))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpyfrom) {
	std::cout << "Copy constructor called" << std::endl;
	_fpval = cpyfrom.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &cpyfrom) {
	std::cout << "Copy assignment operator called" << std::endl;
	
	_fpval = cpyfrom.getRawBits();

	return (*this);
}

std::ostream	&operator <<(std::ostream &outstream, const Fixed &fixedFrom) {
	outstream << fixedFrom.toFloat();
	return (outstream);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (_fpval);
}

void	Fixed::setRawBits(int const raw) {
	_fpval = raw;
}

int	Fixed::toInt(void) const {
	return (_fpval >> _nfrac);
}

float	Fixed::toFloat(void) const {
	return ((float)_fpval / (1 << _nfrac));
}
