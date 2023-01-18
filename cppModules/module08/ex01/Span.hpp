/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:22:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:08 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &cpyFrom);
		Span &operator=(const Span &cpyFrom);
		~Span();

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

	private:
		unsigned int		_N;
		int					_lowest;
		int					_highest;
		std::vector<int>	_storage;
};

#endif
