/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/26 11:39:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl01;

	std::cout << "Calling all of Harl\'s levels in order\n[DEBUG, INFO, WARNING, ERROR]:\n" << std::endl;
	harl01.complain("DEBUG");
	std::cout << std::endl;
	harl01.complain("INFO");
	std::cout << std::endl;
	harl01.complain("WARNING");
	std::cout << std::endl;
	harl01.complain("ERROR");
	std::cout << std::endl;
}
