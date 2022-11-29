/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/29 11:56:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Canonical class shite:
Cat::Cat() {
	std::cout << "Calling default Cat constructor." << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &cpyFrom) : Animal() {
	std::cout << "Calling copy Cat constructor." << std::endl;
	*this = cpyFrom;
}

Cat &Cat::operator=(const Cat &cpyFrom) {
	std::cout << "Calling copy Cat operator." << std::endl;
	_type = cpyFrom._type;
	delete _brain;
	_brain = new Brain();
	return (*this);
}

Cat::~Cat() {
	std::cout << "Calling default Cat destructor." << std::endl;
	delete _brain;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Cat::makeSound(void) const {
	std::cout << "*Meow*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
