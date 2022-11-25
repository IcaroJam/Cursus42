/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/25 19:34:53 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Canonical class shite:
Dog::Dog() {
	std::cout << "Calling default Dog constructor." << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &cpyFrom) : Animal() {
	std::cout << "Calling copy Dog constructor." << std::endl;
	*this = cpyFrom;
}

Dog &Dog::operator=(const Dog &cpyFrom) {
	std::cout << "Calling copy Dog operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Calling default Dog destructor." << std::endl;
	delete _brain;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Dog::makeSound(void) const {
	std::cout << "*Bark*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
