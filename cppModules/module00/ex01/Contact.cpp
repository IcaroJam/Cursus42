/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:52:25 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/03 15:34:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

bool	field_check(std::string str) {
	fail_check();
	if (str == "")
		return true;
	else
		std::cout << "Field saved as \"" << str << "\".\n";
	return false;
}

bool	Contact::field_stuff() {
	std::string	dummystr;

	std::cout << "Enter first name: ";
	std::cin >> _firstname;
	std::getline(std::cin, dummystr);
	if (field_check(_firstname))
		return true;
	std::cout << "Enter last name: ";
	std::cin >> _lastname;
	std::getline(std::cin, dummystr);
	if (field_check(_lastname))
		return true;
	std::cout << "Enter nickname: ";
	std::cin >> _nickname;
	std::getline(std::cin, dummystr);
	if (field_check(_nickname))
		return true;
	std::cout << "Enter... darkest secret: ";
	std::getline(std::cin, _darkestSecret);
	if (field_check(_darkestSecret))
		return true;
	return false;
}

std::string	Contact::get_field(int i) const {
	if (!i)
		return _firstname;
	if (i == 1)
		return _lastname;
	if (i == 2)
		return _nickname;
	if (i == 3)
		return _darkestSecret;
	else
		return "";
}
