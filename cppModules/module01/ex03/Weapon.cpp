/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:04:02 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 16:02:20 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
	_type = "";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon(void) {
}

const std::string	&Weapon::getType(void) const {
	return (_type);
}

void	Weapon::setType(std::string newType) {
	_type = newType;
}
