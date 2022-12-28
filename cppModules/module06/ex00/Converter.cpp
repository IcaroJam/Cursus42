/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:12 by senari            #+#    #+#             */
/*   Updated: 2022/12/28 19:06:43 by senari           ###   ########.fr       */
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
Converter::Converter() : _inStr(""), _cval(0), _ival(0), _fval(0.0f), _dval(0.) {
	_plausible[0] = true;
	_plausible[1] = true;
	_plausible[2] = true;
	_plausible[3] = true;
}

Converter::Converter(const char *givenString) : _cval(0), _ival(0), _fval(0.0f), _dval(0.) {
	_inStr = givenString;
	_plausible[0] = true;
	_plausible[1] = true;
	_plausible[2] = true;
	_plausible[3] = true;

	plausibilityCheck();
	typeConversion();
	convDisplay();
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
		definedType = convChar;
	} else {
		// Digit correctness:
		std::string::size_type	i = 0;
		if (_inStr[0] == '-')
			i++;
		while (_inStr[i] && std::isdigit(_inStr[i]))
			i++;
		if (!_inStr[i]) {
			definedType = convInt;
		 } else if (_inStr[i] == '.') {
			definedType = convDouble;
			i++;
			while (_inStr[i] && std::isdigit(_inStr[i]))
				i++;
			if (_inStr[i] == 'f') {
				if (!_inStr[i + 1]) {
					definedType = convFloat;
				} else
					definedType = convBad;
			} else if (_inStr[i])
				definedType = convBad;
		} else if (_inStr[i] == 'f' && !_inStr[i + 1]) {
			definedType = convFloat;
		} else
			definedType = convBad;
	}
	// DEBUG:
	std::cout << definedType << std::endl;
}

void	Converter::typeConversion(void) {
	switch (definedType) {
		// Single chars have already been handled. Digit to char will be during casting.
		case convChar:
			break;
		case convInt:
			_ival = std::atoi(_inStr.c_str());
			_fval = static_cast<float>(_ival);
			_dval = static_cast<double>(_ival);
			break;
		case convFloat:
			_fval = std::atof(_inStr.c_str());
			_ival = static_cast<int>(_fval);
			_dval = static_cast<double>(_fval);
			break;
		case convDouble:
			_dval = std::atof(_inStr.c_str());
			_ival = static_cast<int>(_dval);
			_fval = static_cast<float>(_dval);
			break;
		case convBad:
			break;
	}
}

void	Converter::convDisplay(void) {
	// Chars:
	std::cout << "Char:   ";
	if (!_plausible[convChar])
		std::cout << "Impossible" << std::endl;
	else if (_ival > 31 && _ival < 127)
		std::cout << "\'" << _cval << "\'" << std::endl;
	else
	    std::cout << "Non-displayable" << std::endl;
	// Ints:
	std::cout << "Int:    " << _ival << std::endl;
	// Floats:
	std::cout << "Float:  " << _fval << std::endl;
	// Doubles:
	std::cout << "Double: " << _dval << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
