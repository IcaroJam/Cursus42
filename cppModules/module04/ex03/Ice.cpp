/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:57:54 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/04 12:28:56 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Canonical class shite:
Ice::Ice() {
	_type = "ice";
}

Ice::Ice(const Ice &cpyFrom) : AMateria("ice") {
	*this = cpyFrom;
}

Ice &Ice::operator=(const Ice &cpyFrom) {
	// Assigning _type seems useless since they are both Ice in every case
	(void)cpyFrom;
	return (*this);
}

Ice::~Ice() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
Ice	*Ice::clone(void) const {
	return (new Ice());
}

void		Ice::use(ICharacter &target) const {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
