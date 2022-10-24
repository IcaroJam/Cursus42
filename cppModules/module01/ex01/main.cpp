/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:35:05 by senari            #+#    #+#             */
/*   Updated: 2022/10/24 11:50:52 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

void	leakCheck(void) {
	system("leaks ZombiesHordeNight");
}

int	main(void) {
	Zombie	*horde;

	horde = zombieHorde(7, "Polliethaniel");
	std::cout << "A horde is coming from the west!" << std::endl;
	for (int i = 0; i < 7; i++) {
		std::cout << "Member of i=" << i << "-> ";
		horde[i].announce();
	}
	std::cout << "Killing them walkers..." << std:: endl;
	delete [] horde;
	atexit(leakCheck);
	return (0);
}
