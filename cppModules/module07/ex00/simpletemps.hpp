/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpletemps.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:28:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:34:40 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLETEMPS_HPP
#define SIMPLETEMPS_HPP

template<typename T> void swap(T &a, T &b) {
	const T	temp = a;

	a = b;
	b = temp;
}

template<typename T> const T &min(const T &a, const T &b) {return (a < b ? a : b);}

template<typename T> const T &max(const T &a, const T &b) {return (a > b ? a : b);}

#endif
