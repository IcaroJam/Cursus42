/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/26 11:56:16 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl01;

	if (argc != 2) {
		std::cerr << "harlFilter must be called as: \"./harlFilter [DEBUG|INFO|WARNING|ERROR]\"" << std::endl;
		return (1);
	}
	harl01.filter(argv[1]);
}
