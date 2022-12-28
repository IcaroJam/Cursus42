/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:12 by senari            #+#    #+#             */
/*   Updated: 2022/12/28 20:13:54 by senari           ###   ########.fr       */
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
static bool	overflowCheck(const std::string &str) {
	long					temp = 0;
	std::string::size_type	i = 0;

	if (str[0] == '-') {
		i++;
		temp -= str[i++] + '0';
		while (std::isdigit(str[i])) {
			temp *= 10;
			temp += str[i++] + '0';
			if (temp < std::numeric_limits<int>::min())
				return true;
		}
	} else {
		while (std::isdigit(str[i])) {
			temp *= 10;
			temp += str[i++] + '0';
			if (temp > std::numeric_limits<int>::max())
				return true;
		}
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Converter::plausibilityCheck(void) {
	// Char specific:
	if (_inStr.length() == 1 && !std::isdigit(_inStr[0])) {
		_cval = _inStr[0];
		definedType = convChar;
		_plausible[convInt] = false;
		_plausible[convFloat] = false;
		_plausible[convDouble] = false;
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
	if (overflowCheck(_inStr))
		_plausible[convInt] = false;

	switch (definedType) {
		case convChar:
			break;
		case convInt:
			if (_plausible[convInt]) {
				_ival = std::atoi(_inStr.c_str());
				_cval = static_cast<char>(_ival);
				_fval = static_cast<float>(_ival);
				_dval = static_cast<double>(_ival);
			} else {
				_fval = atof(_inStr.c_str());
				_dval = atof(_inStr.c_str());
			}
			break;
		case convFloat:
			_fval = std::atof(_inStr.c_str());
			_ival = static_cast<int>(_fval);
			_cval = static_cast<char>(_ival);
			_dval = static_cast<double>(_fval);
			break;
		case convDouble:
			_dval = std::atof(_inStr.c_str());
			_ival = static_cast<int>(_dval);
			_cval = static_cast<char>(_ival);
			_fval = static_cast<float>(_dval);
			break;
		case convBad:
			break;
	}

	if (!_plausible[convInt] || _ival < 0 || _ival > 127)
		_plausible[convChar] = false;
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
	std::cout << "Int:    ";
	if (_plausible[convInt])
		std::cout << _ival << std::endl; // Overflows should be checked for here.
	else
		std::cout << "Impossible" << std::endl;
	// Floats:
	std::cout << "Float:  " << _fval << std::endl; // Overflows and 'nan/+inf/-inf' should be checked for here.
	// Doubles:
	std::cout << "Double: " << _dval << std::endl; // Overflows and 'nan/+inf/-inf' should be checked for here.
}
////////////////////////////////////////////////////////////////////////////////
