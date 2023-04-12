/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:37:27 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/12 12:04:49 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Aid functions:
static int	valiDate(const std::string &str, const std::string &separator) {
	unsigned int	i = 0;

	// First, check date is in YYYY-MM-DD format.
	while (i < 4 && std::isdigit(str[i]))
		i++;
	if (i != 4 || str[i] != '-')
		return (1);
	i++;
	while (i < 7 && std::isdigit(str[i]))
		i++;
	if (i != 7 || str[i] != '-')
		return (1);
	i++;
	while (i < 10 && std::isdigit(str[i]))
		i++;

	// Check separator.
	if (separator == ",") {
		if (i != 10 || str[i] != ',')
			return (1);
		i++;
	}
	else if (separator == " | ") {
		if (i != 10 || !(str[i] == ' ' && str[i + 1] == '|' && str[i + 2] == ' '))
			return (1);
		i += 3;
	}

	// Then check if the remainding characters conform a positive decimal num.
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '.' && str[i] != '\n' && str[i] != 0)
		return (1);
	if (str[i] == '.') {
		i++;
		while (std::isdigit(str[i]))
			i++;
		if (str[i] != '\n' && str[i] != 0)
			return (1);
	}
	return (0);
}

static bool	checkey(std::string &date, const std::map<std::string, float> &db) {
	if (date < db.begin()->first) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (db.find(date) == db.end()) {
		std::cout << "(~" << date << ") ";
		std::map<std::string, float>::const_iterator low = db.lower_bound(date);
		if (low != db.begin())
			low--;
		date = low->first;
	}
	return true;
}

static bool	checkval(float val) {
	if (val >= 0 && val <= 1000)
		return true;
	std::cerr << "Error: number out of range [0, 1000]." << std::endl;
	return false;
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
			std::cerr << "Fatal error1: 'data.csv' is corrupted or umproperly formatted." << std::endl;
			std::cerr << dummy << std::endl;
			return;
		}
		std::string	key = dummy.substr(0, 10);
		float		val = std::atof(dummy.substr(11).c_str());
		_vals.insert(std::pair<std::string, float>(key, val));
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
	if (dummy != "date | value") {
		std::cerr << "Error: '" << fileIn << "' is corrupted or umproperly formatted." << std::endl;
		return;
	}
	while (std::getline(streamin, dummy)) {
		if (valiDate(dummy, " | ")) {
			std::cerr << "Error: bad input => " << dummy << std::endl;
			continue;
		}
		std::string	key = dummy.substr(0, 10);
		float		val = std::atof(dummy.substr(13).c_str());
		// Do the calculations and print the result if everything's fine
		if (checkey(key, _vals) && checkval(val))
			std::cout << key << " => " << val << "btc = " << val * _vals[key] << "USD" << std::endl;
	}
}
////////////////////////////////////////////////////////////////////////////////
