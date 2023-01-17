/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:36:34 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/17 11:13:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include <iostream>

template<typename T> class Array {
	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array &cpyFrom);
		Array<T> &operator=(const Array &cpyFrom);
		~Array();

		T &operator[](unsigned int i) const;

		unsigned int	size(void) const;

	private:
		T				*_arr;
		unsigned int	_len;
};

#include "Array.tpp"

#endif
