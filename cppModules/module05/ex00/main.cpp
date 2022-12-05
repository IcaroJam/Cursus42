/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/05 16:09:16 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat first, second("Bill", 37), third(second);

	std::cout << "Buros present:\n"
				<< first << std::endl
				<< second << std::endl
				<< third << std::endl << std::endl;

	for (int i = 0; i < 36; i++)
		second.gradeInc();

	std::cout << "Buros present:\n"
				<< first << std::endl
				<< second << std::endl
				<< third << std::endl << std::endl;

	try {
		second.gradeInc();
	} catch (std::exception &exep) {
		std::cout << exep.what() << std::endl;
	}
	
	std::cout << "Buros present:\n"
				<< first << std::endl
				<< second << std::endl
				<< third << std::endl << std::endl;

	third = second;
	for (int i = 0; i < 149; i++)
		third.gradeDec();

	std::cout << "Buros present:\n"
				<< first << std::endl
				<< second << std::endl
				<< third << std::endl << std::endl;

	try {
		third.gradeDec();
	} catch (std::exception &exep) {
		std::cout << exep.what() << std::endl;
	}
	
	std::cout << "Attempting to instantiate: Bureaucrat fourth(\"Exceptio Marcía\", 0)." << std::endl;

	try {
		Bureaucrat fourth("Exceptio Marcía", 0);
	} catch (std::exception &exep) {
		std::cout << exep.what() << std::endl;
	}
}
