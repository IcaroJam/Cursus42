/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:37:27 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/11 19:59:24 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Aid functions:
int	valiDate(const std::string &str, const std::string &separator) {
	unsigned int	i = 0;

	// First, check date is in YYYY-MM-DD format.
	while (i < 4 && std::isdigit(str[i]))
		i++;
	if (i != 4 || str[i] != '-')
		return (1);
	while (i < 6 && std::isdigit(str[i]))
		i++;
	if (i != 6 || str[i] != '-')
		return (1);
	while (i < 8 && std::isdigit(str[i]))
		i++;

	// Check separator.
	if (separator == ",") {
		if (i != 8 || str[i] != ',')
			return (1);
		i++;
	}
	else if (separator == " | ") {
		if (i != 8 || !(str[i] == ' ' && str[i + 1] == '|' && str[i + 2] == ' '))
			return (1);
		i += 3;
	}

	// Then check if the remainding characters conform a positive decimal num.
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '.' && str[i] != '\n' && str[i] != 0)
		return (1);
	if (str[i] == '.') {
		while (std::isdigit(str[i]))
			i++;
		if (str[i] != '\n' && str[i] != 0)
			return (1);
	}
	return (0);
}
////////////////////////////////////////////////////////////////////////////////
// Canonical class shite:
BitcoinExchange::BitcoinExchange() : _vals() {
	std::ifstream	streamin("./data.csv");
	std::string		dummy;

	if (!streamin) {
		std::cerr << "Fatal error: 'data.csv' wasn't found or could not be opened." << std::endl;
		return;
	}
	std::getline(streamin, dummy);
	if (dummy != "date,exchange_rate") {
		std::cerr << "Fatal error: 'data.csv' is corrupted or umproperly formatted." << std::endl;
		return;
	}
	while (std::getline(streamin, dummy)) {
		if (valiDate(dummy, ",")) {
			std::cerr << "Fatal error: 'data.csv' is corrupted or umproperly formatted." << std::endl;
			return;
		}
		std::string	key = dummy.substr(0, 10);
		float		val = std::atof(dummy.substr(11).c_str());
		_vals.insert({key, val});
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpyFrom) {
	*this = cpyFrom;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpyFrom) {
	_vals = cpyFrom._vals;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	BitcoinExchange::printMoneys(const char *fileIn) {
	std::ifstream	streamin(fileIn);
	std::string		dummy;

	if (!streamin) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::getline(streamin, dummy);
	if (dummy != "date | exchange_rate") {
		std::cerr << "Error: '" << fileIn << "' is corrupted or umproperly formatted." << std::endl;
		return;
	}
	while (std::getline(streamin, dummy)) {
		if (valiDate(dummy, " | ")) {
			std::cerr << "Error: bad input => " << dummy << std::endl;
			return;
		}
		std::string	key = dummy.substr(0, 10);
		// Check date stuff here
		float		val = std::atof(dummy.substr(11).c_str());
		// Check for value stuff here
		//
		// Do the calculations and print the result if everything's fine
	}
}
////////////////////////////////////////////////////////////////////////////////
