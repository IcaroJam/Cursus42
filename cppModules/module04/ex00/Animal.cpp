/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/24 17:31:50 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Canonical class shite:
Animal::Animal() {
	std::cout << "Calling default Animal constructor." << std::endl;
	_type = "Unknown";
}

Animal::Animal(const Animal &cpyFrom) {
	std::cout << "Calling copy Animal constructor." << std::endl;
	*this = cpyFrom;
}

Animal &Animal::operator=(const Animal &cpyFrom) {
	std::cout << "Calling copy Animal operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Calling default Animal destructor." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
std::string	Animal::getType(void) const {
	return (_type);
}

void		Animal::makeSound(void) const {
	std::cout << "*Mysterious sound*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
