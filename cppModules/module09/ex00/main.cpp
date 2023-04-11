/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:46:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/11 17:52:51 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	BitcoinExchange	btcEx;

	if (argc < 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	btcEx.printMoneys(argv[1]);
	return (0);
}
