/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/26 14:27:31 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Canonical class shite:
WrongAnimal::WrongAnimal() {
	std::cout << "Calling default WrongAnimal constructor." << std::endl;
	_type = "Unknown";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpyFrom) {
	std::cout << "Calling copy WrongAnimal constructor." << std::endl;
	*this = cpyFrom;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpyFrom) {
	std::cout << "Calling copy WrongAnimal operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Calling default WrongAnimal destructor." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "*Mysterious sound*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
