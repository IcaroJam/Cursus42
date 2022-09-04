/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:03:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/04 18:05:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
		std::cout << "\nError!\nNo field can be left empty.\n";
		return;
	}
	if (_lastContact == 8)
		book_reorg();
	_contactArray[_lastContact] = temp;
	std::cout << "Contact saved!\n";
	_lastContact++;
}

std::string	formatter(std::string str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

void	print_contact(Contact const &temp) {
	std::cout << temp.get_field(0) << "\n";
	std::cout << temp.get_field(1) << "\n";
	std::cout << temp.get_field(2) << "\n";
	std::cout << temp.get_field(3) << "\n";
}

void	PhoneBook::contact_display() const {
	int			contactIndex;
	std::string	dummy;

	std::cout << std::setiosflags(std::ios::right);
	for (int i = 0; i < _lastContact; i++) {
		std::cout	<< "|" << std::setw(10) << i 
					<< "|" << std::setw(10) << formatter(_contactArray[i].get_field(0))
					<< "|" << std::setw(10) << formatter(_contactArray[i].get_field(1))
					<< "|" << std::setw(10) << formatter(_contactArray[i].get_field(2)) << "|\n";
	}
	std::cout << std::resetiosflags(std::ios::right);
	std::cout << "Enter index of contact to display: ";
	std::cin >> contactIndex;
	std::getline(std::cin, dummy);
	if (std::cin.fail() || contactIndex < 0 || contactIndex > _lastContact - 1) {
		fail_check();
		std::cout << "Invalid index.\n";
		return;
	}
	print_contact(_contactArray[contactIndex]);
}
