/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:55:37 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/17 11:35:06 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

void	leaksCheck(void) {
	system("leaks classyArrays");
}

int	main(void) {
	atexit(leaksCheck);

	Array<int>			a1;
	Array<char>			a2;
	Array<char *>		a3;
	Array<std::string>	a4;

	std::cout	<< "Four empty arrays were just created." << std::endl
				<< "a1 size: " << a1.size() << std::endl
				<< "a2 size: " << a2.size() << std::endl
				<< "a3 size: " << a3.size() << std::endl
				<< "a4 size: " << a4.size() << std::endl
				<< "Attempting to access a1[0]: ";
	try {
		std::cout << a1[0];
	} catch (std::exception &exep) {
		std::cerr << exep.what() << std::endl;
	}

	Array<int>			b1(3);
	Array<char>			b2(3);
	Array<char *>		b3(3);
	Array<std::string>	b4(3);

	std::cout	<< "Four arrays of size 3 were just created." << std::endl
				<< "b1 size: " << b1.size() << std::endl
				<< "b2 size: " << b2.size() << std::endl
				<< "b3 size: " << b3.size() << std::endl
				<< "b4 size: " << b4.size() << std::endl
				<< "Attempting to access b1[2]: " << b1[2] << std::endl
				<< "Attempting to access b2[2]: " << b2[2] << std::endl
				<< "Attempting to access b3[2]: " << "(This would result in a segfault since pointers default initialize to NULL)" << std::endl
				<< "Attempting to access b4[2]: " << b4[2] << std::endl;
	std::cout << "Attempting to access b3[3]: ";
	try {
		std::cout << b3[3];
	} catch (std::exception &exep) {
		std::cerr << exep.what() << std::endl;
	}
}
