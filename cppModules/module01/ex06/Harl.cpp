/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:10:11 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/26 11:57:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*funcptrs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levelmap[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;

	for (i = 0; i < 4; i++) {
		if (levelmap[i] == level) {
			(this->*funcptrs[i])();
			break;
		}
	}
	if (i == 4)
		std::cout << "level provided fell out of Harl\'s reach." << std::endl;
}

void	Harl::filter(std::string level) {
	void	(Harl::*funcptrs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levelmap[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;

	for (i = 0; i < 4; i++) {
		if (levelmap[i] == level)
			break;
	}

	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*funcptrs[0])();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*funcptrs[1])();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*funcptrs[2])();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*funcptrs[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
