/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:57:54 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:54:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Canonical class shite:
Cure::Cure() {
	_type = "cure";
}

Cure::Cure(const Cure &cpyFrom) : AMateria("cure") {
	*this = cpyFrom;
}

Cure &Cure::operator=(const Cure &cpyFrom) {
	// Assigning _type seems useless since they are both Cure in every case
	(void)cpyFrom;
	return (*this);
}

Cure::~Cure() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
Cure	*Cure::clone(void) const {
	return (new Cure());
}

void		Cure::use(ICharacter &target) const {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
