/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:37:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/13 11:41:32 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Error: No operations provided." << std::endl;
		return (1);
	}

	Rpn	rpn_stack;
	for (int i = 1; i < argc; i++)
		if (rpn_stack.printResult(argv[i]))
			return (1);
	return (0);
}
