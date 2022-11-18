/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/18 12:59:52 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap	a("1"), b, c(a);

	a.takeDamage(9);
	a.takeDamage(9);
	a.takeDamage(1);
	a.beRepaired(12);
	for (int i = 0; i < 10; i++) {
		a.attack("a presumptuous asshole");
	}
	return 0;
}
