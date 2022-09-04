/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:52:25 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/04 14:16:06 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

bool	field_check(std::string str) {
	if (str == "")
		return true;
	else
		std::cout << "Field saved as \"" << str << "\".\n";
	return false;
}

bool	Contact::field_stuff() {
	std::cout << "Enter first name: ";
	std::cin >> _firstname;
	if (field_check(_firstname))
		return true;
	std::cout << "Enter last name: ";
	std::cin >> _lastname;
	if (field_check(_lastname))
		return true;
	std::cout << "Enter nickname: ";
	std::cin >> _nickname;
	if (field_check(_nickname))
		return true;
	std::cout << "Enter... darkest secret: ";
	std::cin >> _darkestSecret;
	if (field_check(_darkestSecret))
		return true;
	return false;
}
