/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:15:26 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:07:28 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Canonical class shite:
AMateria::AMateria() : _type("undefined materia") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &cpyFrom) {
	*this = cpyFrom;
}

AMateria &AMateria::operator=(const AMateria &cpyFrom) {
	(void)cpyFrom;
	return (*this);
}

AMateria::~AMateria() {}
////////////////////////////////////////////////////////////////////////////////
// Member class functions:
const std::string	&AMateria::getType(void) const {
	return (_type);
}

void	AMateria::use(ICharacter &target) const {
	std::cout << "An undefined materia is used on " << target.getName() << "!!! What will the outcome of this preposterous happening be?" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
