/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:12 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 20:33:43 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

enum	convTypes {
	convChar,
	convInt,
	convFloat,
	convDouble,
	convBad
}		definedType;

// Canonical class shite:
Converter::Converter() {}
Converter::Converter(const char *givenString) {
	_inStr = givenString;
	_plausible[0] = false;
	_plausible[1] = false;
	_plausible[2] = false;
	_plausible[3] = false;

	plausibilityCheck();
}

Converter::Converter(const Converter &cpyFrom) {(void)cpyFrom;}

Converter &Converter::operator=(const Converter &cpyFrom) {(void)cpyFrom; return (*this);}

Converter::~Converter() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Converter::plausibilityCheck(void) {
	// Char specific:
	if (_inStr.length() == 1 && !std::isdigit(_inStr[0])) {
		_cval = _inStr[0];
		_plausible[convChar] = true;
		definedType = convChar;
	}

	// Digit correctness:
	std::string::size_type	i = 0;
	if (_inStr[0] == '-')
		i++;
	if (std::isdigit(_inStr[i]))
		definedType = convInt;
	while (i < _inStr.length() && std::isdigit(_inStr[i]))
		i++;
	if (_inStr[i] == '.') {
		definedType = convDouble;
		i++;
		while (i < _inStr.length() && std::isdigit(_inStr[i]))
			i++;
	}
	if (_inStr[i] == 'f' && !_inStr[i + 1]) {
		_plausible[convDouble] = true;
		_plausible[convFloat] = true;
		definedType = convFloat;
	} else if (_inStr[i]) {
		definedType = convBad;
	}
}
////////////////////////////////////////////////////////////////////////////////
