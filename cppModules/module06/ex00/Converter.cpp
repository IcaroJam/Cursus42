/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:12 by senari            #+#    #+#             */
/*   Updated: 2023/01/05 12:18:50 by senari           ###   ########.fr       */
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

	typeCheck();
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
		temp -= str[i++] - '0';
		while (std::isdigit(str[i])) {
			temp *= 10;
			temp += str[i++] - '0';
			if (temp < std::numeric_limits<int>::min())
				return true;
		}
	} else {
		while (std::isdigit(str[i])) {
			temp *= 10;
			temp += str[i++] - '0';
			if (temp > std::numeric_limits<int>::max())
				return true;
		}
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
bool	Converter::weirdValsCheck(std::string str) {
	for (int i = 0; i < 5 && str[i]; i++)
		str[i] = std::tolower(str[i]);
	if (str == "nanf" || str == "+inff" || str == "-inff") {
		definedType = convFloat;
		return true;
	}
	if (str == "nan" || str == "+inf" || str == "-inf") {
		definedType = convDouble;
		return true;
	}
	return false;
}

void	Converter::typeCheck(void) {
	// Char specific:
	if (_inStr.length() == 1 && !std::isdigit(_inStr[0])) {
		definedType = convChar;
		_plausible[convInt] = false;
		_plausible[convFloat] = false;
		_plausible[convDouble] = false;
	} else if (weirdValsCheck(_inStr)) {
		_plausible[convChar] = false;
		_plausible[convInt] = false;
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
				} else {
					definedType = convBad;
					_plausible[0] = false;
					_plausible[1] = false;
					_plausible[2] = false;
					_plausible[3] = false;
				}
			} else if (_inStr[i])
				definedType = convBad;
		} else if (_inStr[i] == 'f' && !_inStr[i + 1]) {
			definedType = convFloat;
		} else {
			definedType = convBad;
			_plausible[0] = false;
			_plausible[1] = false;
			_plausible[2] = false;
			_plausible[3] = false;
		}
	}
}

void	Converter::typeConversion(void) {
	if (overflowCheck(_inStr))
		_plausible[convInt] = false;

	switch (definedType) {
		case convChar:
			_cval = _inStr[0];
			break;
		case convInt:
			if (_plausible[convInt]) {
				_ival = std::atoi(_inStr.c_str());
				_cval = static_cast<char>(_ival);
				_fval = static_cast<float>(_ival);
				_dval = static_cast<double>(_ival);
			} else {
				_fval = atof(_inStr.c_str());
				if (std::isinf(_fval)) {
					_plausible[convFloat] = false;
					_dval = std::atof(_inStr.c_str());
					if (std::isinf(_dval))
						_plausible[convDouble] = false;
					break;
				}
				_dval = atof(_inStr.c_str());
			}
			break;
		case convFloat:
			_fval = std::atof(_inStr.c_str());
			if (std::isinf(_fval)) {
				_plausible[convFloat] = false;
				_dval = std::atof(_inStr.c_str());
				if (std::isinf(_dval))
					_plausible[convDouble] = false;
				break;
			}
			_ival = static_cast<int>(_fval);
			_cval = static_cast<char>(_ival);
			_dval = static_cast<double>(_fval);
			break;
		case convDouble:
			_dval = std::atof(_inStr.c_str());
			if (std::isinf(_dval)) {
				_plausible[convFloat] = false;
				_plausible[convDouble] = false;
				break;
			}
			_ival = static_cast<int>(_dval);
			_cval = static_cast<char>(_ival);
			_fval = static_cast<float>(_dval);
			if (std::isinf(_fval))
				_plausible[convFloat] = false;
			break;
		case convBad:
			break;
	}

	if (definedType != convChar && (!_plausible[convInt] || _ival < 0 || _ival > 127))
		_plausible[convChar] = false;
}

void	Converter::convDisplay(void) {
	// Chars:
	std::cout << "Char:   ";
	if (!_plausible[convChar])
		std::cout << "Impossible" << std::endl;
	else if (definedType == convChar || (_ival > 31 && _ival < 127))
		std::cout << "\'" << _cval << "\'" << std::endl;
	else
	    std::cout << "Non-displayable" << std::endl;

	// Ints:
	std::cout << "Int:    ";
	if (_plausible[convInt])
		std::cout << _ival << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	// Floats:
	std::cout << "Float:  ";
	if (_plausible[convFloat]) {
		std::cout << _fval;
		if (!std::isinf(_fval) && !std::isnan(_fval)) {
			if (std::floor(_fval) == _fval && _fval < 1000000 && _fval > -1000000)
				std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;

	// Doubles:
	std::cout << "Double: ";
	if (_plausible[convDouble]) {
		std::cout << _dval;
		if (!std::isinf(_dval) && !std::isnan(_dval)) {
			if (std::floor(_dval) == _dval && _dval < 1000000 && _dval > -1000000)
				std::cout << ".0";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
