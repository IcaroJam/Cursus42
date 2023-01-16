/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:23:45 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/16 13:36:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T> void testPrint(T & printThis) {
	std::cout << printThis << std::endl;
}

template<typename arrT> void iter(arrT *arr, std::size_t len, void (*function)(arrT &)) {
	for (std::size_t i = 0; i < len; i++)
	  function(arr[i]);
}

#endif
