/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:53:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/04 13:44:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main() {
	std::string	cmnd;
	PhoneBook	phbook;

	std::cout << "Welcome to your Awesome PhoneBook™!\n";
	while (true) {
		std::cout << "Enter a command [ADD/SEARCH/EXIT]: ";
		std::cin >> cmnd;
		if (cmnd == "ADD") {
			phbook.contact_add();
		} else if (cmnd == "SEARCH") {
			phbook.contact_display();
		} else if (cmnd == "EXIT") {
			break;
		} else if (cmnd == "add" || cmnd == "search" || cmnd == "exit") {
			std::cout << "Sorry sir, ma'am or person, but our current technology doesn't allow for things such as case insensitivity.\n";
		} else {
			std::cout << "Unknown command.\n";
		}
	}
}