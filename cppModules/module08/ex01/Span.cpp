/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:50:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/18 16:16:58 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class no_span_exception : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("No span could be found.");
		}
};

class full_span_exception : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("No numbers could be added. (Full span).");
		}
};

// Canonical class shite:
Span::Span() : _N(0), _lowest(std::numeric_limits<int>::max()), _highest(std::numeric_limits<int>::min()) {}

Span::Span(unsigned int N) : _N(N), _lowest(std::numeric_limits<int>::max()), _highest(std::numeric_limits<int>::min()) {}

Span::Span(const Span &cpyFrom) {
	*this = cpyFrom;
}

Span &Span::operator=(const Span &cpyFrom) {
	_N = cpyFrom._N;
	_lowest = cpyFrom._lowest;
	_highest = cpyFrom._highest;
	_storage = cpyFrom._storage;

	return (*this);
}

Span::~Span() {}
////////////////////////////////////////////////////////////////////////////////
// Member function aid:
static void	spanExceptionCheck(const std::vector<int> &v) {
	if (v.empty() || v.size() < 2)
		throw no_span_exception();
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Span::addNumber(int n) {
	if (_storage.size() == _N)
		throw full_span_exception();
	_storage.push_back(n);
	if (n < _lowest)
		_lowest = n;
	if (n > _highest)
		_highest = n;
}

void	Span::addNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	for (; beg != end; ++beg)
		this->addNumber(*beg);
}

int	Span::shortestSpan(void) {
	spanExceptionCheck(_storage);

	std::sort(_storage.begin(), _storage.end());

	std::vector<int>::iterator	it = _storage.begin() + 1;
	int							ret = it[0] - it[-1];
	int							temp;

	while (++it != _storage.end()) {
		temp = it[0] - it[-1];
		if (temp < ret)
			ret = temp;
	}

	return (ret);
}

int	Span::longestSpan(void) {
	spanExceptionCheck(_storage);
	return (_highest - _lowest);
}
////////////////////////////////////////////////////////////////////////////////
