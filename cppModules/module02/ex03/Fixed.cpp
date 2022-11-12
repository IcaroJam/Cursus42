/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/11 14:22:09 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpval(0) {
	/* std::cout << "Default constructor called" << std::endl; */
}

Fixed::Fixed(const int initVal) : _fpval(initVal << _nfrac) {
	/* std::cout << "Int constructor called" << std::endl; */
}

Fixed::Fixed(const float initVal) : _fpval((int)roundf(initVal * (1 << _nfrac))) {
	/* std::cout << "Float constructor called" << std::endl; */
}

Fixed::Fixed(const Fixed &cpyfrom) {
	/* std::cout << "Copy constructor called" << std::endl; */
	_fpval = cpyfrom.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &cpyfrom) {
	/* std::cout << "Copy assignment operator called" << std::endl; */
	
	_fpval = cpyfrom.getRawBits();

	return (*this);
}

bool Fixed::operator >(const Fixed &rhs) const {
	return (_fpval > rhs.getRawBits());
}

bool Fixed::operator <(const Fixed &rhs) const {
	return (_fpval < rhs.getRawBits());
}

bool Fixed::operator >=(const Fixed &rhs) const {
	return (!Fixed::operator<(rhs));
}

bool Fixed::operator <=(const Fixed &rhs) const {
	return (!Fixed::operator>(rhs));
}

bool Fixed::operator ==(const Fixed &rhs) const {
	return (_fpval == rhs.getRawBits());
}

bool Fixed::operator !=(const Fixed &rhs) const {
	return (_fpval != rhs.getRawBits());
}

Fixed Fixed::operator +(const Fixed &rhs) const {
	Fixed	ret(*this);

	ret.setRawBits(_fpval + rhs.getRawBits());
	return (ret);
}

Fixed Fixed::operator -(const Fixed &rhs) const {
	Fixed	ret(*this);

	ret.setRawBits(_fpval - rhs.getRawBits());
	return (ret);
}

Fixed Fixed::operator *(const Fixed &rhs) const {
	Fixed	ret(*this);

	ret.setRawBits(_fpval * rhs.getRawBits() / (1 << _nfrac));
	return (ret);
}

Fixed Fixed::operator /(const Fixed &rhs) const {
	Fixed	ret(*this);

	ret.setRawBits(_fpval * (1 << _nfrac) / rhs.getRawBits());
	return (ret);
}

Fixed &Fixed::operator ++(void) {
	_fpval++;
	return (*this);
}

Fixed Fixed::operator ++(int) {
	Fixed	ret(*this);
	_fpval++;
	return (ret);
}

Fixed &Fixed::operator --(void) {
	_fpval--;
	return (*this);
}

Fixed Fixed::operator --(int) {
	Fixed	ret(*this);
	_fpval--;
	return (ret);
}

std::ostream	&operator <<(std::ostream &outstream, const Fixed &fixedFrom) {
	outstream << fixedFrom.toFloat();
	return (outstream);
}

Fixed::~Fixed() {
	/* std::cout << "Destructor called" << std::endl; */
}

int	Fixed::getRawBits(void) const {
	/* std::cout << "getRawBits function called" << std::endl; */
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

Fixed	&Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}
