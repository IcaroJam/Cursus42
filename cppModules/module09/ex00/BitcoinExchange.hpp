/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/11 17:35:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <map>
#include <iostream>

class	BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpyFrom);
		BitcoinExchange &operator=(const BitcoinExchange &cpyFrom);
		~BitcoinExchange();

	private:
		std::map<std::string, float>	_vals;
};

#endif
