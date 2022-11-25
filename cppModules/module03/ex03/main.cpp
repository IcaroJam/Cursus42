/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/25 12:57:22 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap	a("1"), b, c(a);

	b = a;
	a.takeDamage(90);
	a.takeDamage(10);
	a.takeDamage(1);
	a.beRepaired(12);
	for (int i = 0; i < 50; i++) {
		a.attack("a presumptuous asshole");
	}
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();
	return 0;
}
