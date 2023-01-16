/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:33:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/16 13:41:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	makeNeg(int & i) {
	if (i < 0)
		i = -i;
}

void	engrandize(char & c) {
	if (std::islower(c))
		c -= 32;
}

int	main(void) {
	int			iarr[3] = {5, -2, 47};
	char		carr[7] = {'g', 'F', '-', '6', 'j', ' ', 'q'};
	std::string	sarr[2] = {"hey", "tHeRe"};

	std::cout << "Int array: " << iarr[0] << ", " << iarr[1] << ", " << iarr[2] << std::endl;
	iter(iarr, 3, makeNeg);
	std::cout << "Int array after iter: " << iarr[0] << ", " << iarr[1] << ", " << iarr[2] << std::endl;
	
    std::cout << "Char array: " << carr[0] << ", " << carr[1] << ", " << carr[2] << carr[3] << ", " << carr[4] << ", " << carr[5] << ", " << carr[6] << std::endl;
	iter(carr, 7, engrandize);
	std::cout << "Char array after iter: " << carr[0] << ", " << carr[1] << ", " << carr[2] << carr[3] << ", " << carr[4] << ", " << carr[5] << ", " << carr[6] << std::endl;

	std::cout << "String array: " << sarr[0] << ", " << sarr[1] << std::endl;
	iter(sarr, 2, testPrint);
    std::cout << "String array after iter: " << sarr[0] << ", " << sarr[1] << std::endl;
}
