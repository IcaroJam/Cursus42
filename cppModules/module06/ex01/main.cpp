/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:55:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:38:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "data.h"

uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int main(void) {
	Data		dstruc;
	Data		*dptr = &dstruc;
	uintptr_t	uiptr = 27;
	Data		*desz = 0;

	std::cout	<< "Og:    " << dptr << std::endl
				<< "Uiptr: " << uiptr << std::endl
				<< "Dsptr: " << desz << std::endl
				<< "Eq?:   " << std::boolalpha << (reinterpret_cast<Data *>(uiptr) == desz) << std::endl;

	uiptr = serialize(dptr);
	desz = deserialize(uiptr);

	std::cout	<< "Og:    " << dptr << std::endl
				<< "Uiptr: " << uiptr << std::endl
				<< "Dsptr: " << desz << std::endl
				<< "Eq?:   " << std::boolalpha << (reinterpret_cast<Data *>(uiptr) == desz) << std::endl;
}
