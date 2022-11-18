/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/18 13:35:52 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap	a("1"), b, c(a);

	a.takeDamage(90);
	a.takeDamage(10);
	a.takeDamage(1);
	a.beRepaired(12);
	for (int i = 0; i < 50; i++) {
		a.attack("a presumptuous asshole");
	}
	a.guardGate();
	return 0;
}
