/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/25 13:06:39 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Canonical class shite:
Cat::Cat() {
	std::cout << "Calling default Cat constructor." << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &cpyFrom) : Animal() {
	std::cout << "Calling copy Cat constructor." << std::endl;
	*this = cpyFrom;
}

Cat &Cat::operator=(const Cat &cpyFrom) {
	std::cout << "Calling copy Cat operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Calling default Cat destructor." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	Cat::makeSound(void) const {
	std::cout << "*Meow*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
