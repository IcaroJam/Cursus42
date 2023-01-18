/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:48:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/18 12:59:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void) {
	Span	s(5);

	std::cout << "Attempting to span on empty:" << std::endl;
	try {
		s.shortestSpan();
	} catch (std::exception & excep) {
		std::cerr << excep.what() << std::endl;
	}

	s.addNumber(-223);
	s.addNumber(3);
	s.addNumber(47);
	s.addNumber(5626);
	s.addNumber(-16674);
	std::cout << "Added to the span: -16674 -223 3 47 5626" << std::endl << "Trying to add another..." << std::endl;
	try {
		s.addNumber(-42);
	} catch (std::exception & excep) {
		std::cerr << excep.what() << std::endl;
	}

	std::cout	<< "Shortest span: " << s.shortestSpan() << std::endl
				<< "Longest span:  " << s.longestSpan() << std::endl;
}
