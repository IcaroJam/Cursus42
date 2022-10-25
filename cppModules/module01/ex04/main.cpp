/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:52:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/25 10:57:47 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	inputCheck(int argc, char **argv) {
	if (argc != 2)
		return (-1);
	return (fdret);
}

int	main(int argc, char **argv) {
	int	fd = inputCheck(argc, argv);

	if (fd < 0)
		std::cout << "Argument error!" << std::endl;
}
