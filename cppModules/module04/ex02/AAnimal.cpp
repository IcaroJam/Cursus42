/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/28 15:38:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Canonical class shite:
AAnimal::AAnimal() {
	std::cout << "Calling default AAnimal constructor." << std::endl;
	_type = "Unknown";
}

AAnimal::AAnimal(const AAnimal &cpyFrom) {
	std::cout << "Calling copy AAnimal constructor." << std::endl;
	*this = cpyFrom;
}

AAnimal &AAnimal::operator=(const AAnimal &cpyFrom) {
	std::cout << "Calling copy AAnimal operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "Calling default AAnimal destructor." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
std::string	AAnimal::getType(void) const {
	return (_type);
}
////////////////////////////////////////////////////////////////////////////////
