/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/21 16:46:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
	FragTrap	a("1"), b, c(a);

	a.takeDamage(90);
	a.takeDamage(10);
	a.takeDamage(1);
	a.beRepaired(12);
	for (int i = 0; i < 100; i++) {
		a.attack("a presumptuous asshole");
	}
	a.highFivesGuys();
	return 0;
}
