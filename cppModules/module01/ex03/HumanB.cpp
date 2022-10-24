/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:35:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:40 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon &nuWpn) {
	_weapon = &nuWpn;
}

void	HumanB::attack(void) {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
