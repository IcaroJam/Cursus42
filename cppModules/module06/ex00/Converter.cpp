/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:12 by senari            #+#    #+#             */
/*   Updated: 2022/12/24 19:20:55 by senari           ###   ########.fr       */
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
Converter::Converter() : _inStr(""), _cval(0), _ival(0), _dval(0.), _fval(0.0f) {
	_plausible[0] = true;
	_plausible[1] = true;
	_plausible[2] = true;
	_plausible[3] = true;
}

Converter::Converter(const char *givenString) {
	_inStr = givenString;
	_plausible[0] = false;
	_plausible[1] = false;
	_plausible[2] = false;
	_plausible[3] = false;

	plausibilityCheck();
}

Converter::Converter(const Converter &cpyFrom) {
	*this = cpyFrom;
}

Converter &Converter::operator=(const Converter &cpyFrom) {
	_inStr = cpyFrom._inStr;
	_cval = cpyFrom._cval;
	_ival = cpyFrom._ival;
	_dval = cpyFrom._dval;
	_fval = cpyFrom._fval;
	_plausible[0] = cpyFrom._plausible[0];
	_plausible[1] = cpyFrom._plausible[1];
	_plausible[2] = cpyFrom._plausible[2];
	_plausible[3] = cpyFrom._plausible[3];
	return (*this);
}

Converter::~Converter() {}
////////////////////////////////////////////////////////////////////////////////
// Aid functions:

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
	while (_inStr[i] && std::isdigit(_inStr[i]))
		i++;
	if (!_inStr[i])
		definedType = convInt;
	else if (_inStr[i] == '.') {
		_plausible[convDouble] = true;
		definedType = convDouble;
		i++;
		while (_inStr[i] && std::isdigit(_inStr[i]))
			i++;
		if (_inStr[i] == 'f') {
			if (!_inStr[i + 1]) {
				_plausible[convFloat] = true;
				definedType = convFloat;
			} else
				definedType = convBad;
		} else if (_inStr[i])
			definedType = convBad;
	} else
		definedType = convBad;
}
////////////////////////////////////////////////////////////////////////////////
