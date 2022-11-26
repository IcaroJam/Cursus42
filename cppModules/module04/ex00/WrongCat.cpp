/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:58 by senari            #+#    #+#             */
/*   Updated: 2022/11/26 14:31:50 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Canonical class shite:
WrongCat::WrongCat() {
	std::cout << "Calling default WrongCat constructor." << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cpyFrom) : WrongAnimal() {
	std::cout << "Calling copy WrongCat constructor." << std::endl;
	*this = cpyFrom;
}

WrongCat &WrongCat::operator=(const WrongCat &cpyFrom) {
	std::cout << "Calling copy WrongCat operator." << std::endl;
	_type = cpyFrom._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Calling default WrongCat destructor." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	WrongCat::makeSound(void) const {
	std::cout << "*Meow*" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
