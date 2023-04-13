/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:52:30 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/13 11:40:55 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Aid functions:
static bool	isoperator(const char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static int	getresult(std::stack<int> &_stck, const char op) {
	const int	right = _stck.top();
	_stck.pop();
	const int	left = _stck.top();
	_stck.pop();
	int	result;

	switch (op) {
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
		result = left / right;
		break;
	}
	return (result);
}
////////////////////////////////////////////////////////////////////////////////
// Canonical class shite:
Rpn::Rpn() {}

Rpn::Rpn(const Rpn &cpyFrom) {
	*this = cpyFrom;
}

Rpn &Rpn::operator=(const Rpn &cpyFrom) {
	_stck = cpyFrom._stck;
	return (*this);
}

Rpn::~Rpn() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
int	Rpn::printResult(const char *op) {
	for (int i = 0; op[i]; i++) {
		while (op[i] && op[i] == ' ')
			i++;
		if (isdigit(op[i]) && !isdigit(op[i + 1]))
			_stck.push(std::atoi(&op[i]));
		else if (isoperator(op[i])) {
			if (_stck.size() < 2) {
				std::cout << "Error: Attempted to perform operation on a single number." << std::endl;
				return (1);
			}
			_stck.push(getresult(_stck, op[i]));
		}
		else {
			std::cout << "Error: invalid character(s)." << std::endl;
			return (1);
		}
	}
	if (_stck.size() == 1)
		std::cout << _stck.top() << std::endl;
	else {
		std::cout << "Error: More than one element left in stack after operation(s)." << std::endl;
		return (1);
	}
	return (0);
}
////////////////////////////////////////////////////////////////////////////////
