/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:54 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/13 13:12:47 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool onlydigits(const std::string &str) {
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

int	main(int argc, char **argv) {
	// Check the input.
	if (argc == 1) {
		std::cerr << "Error: No numbers provided." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++) {
		if (!onlydigits(argv[i])) {
			std::cerr << "Error: Argument '" << argv[i] << "' isn't a positive number." << std::endl;
			return (1);
		}
	}

	PmergeMe	business;
	// This fills the containers with the unordered values. If a number overflows the int, it prints an error message and returns 1:
	if (!business.fillherup(&argv[1]))
	    business.performtest(); // This sorts the containers, measuring the elapsed time and printing everything.

	return (0);
}
