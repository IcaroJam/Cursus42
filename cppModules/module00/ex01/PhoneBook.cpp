/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:03:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/04 14:18:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _lastContact(0) {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::book_reorg() {
	for (int i = 0; i < 7; i++) {
		_contactArray[i] = _contactArray[i + 1];
	}
	_lastContact--;
}

void	PhoneBook::contact_add() {
	Contact	temp;

	if (temp.field_stuff()) {
		std::cout << "Error!\nNo field can be left empty.\n";
		return;
	}
	if (_lastContact == 7)
		book_reorg();
	_contactArray[_lastContact] = temp;
	std::cout << "Contact saved!\n";
	_lastContact++;
}
