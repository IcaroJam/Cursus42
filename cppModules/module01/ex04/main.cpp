/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:52:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/25 13:48:54 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	inputCheck(int argc, char **argv, std::ifstream &input, std::ofstream &output) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments.\n" << std::endl;
		return (-1);
	}
	input.open(argv[1]);
	if (!input.is_open()) {
		std::cerr << "Failed to open " << argv[1] << std::endl;
		return (-1);
	}
	std::string	outname(argv[1]);
	outname += ".replace";
	output.open(outname);
	if (!output.is_open()) {
		std::cerr << "Failed to open " << outname << std::endl;
		return (-1);
	}
	return (0);
}

void	placeAgain(char **argv, std::ifstream &input, std::ofstream &output) {
	std::string	tempstr;
	size_t		currpos;

	while (!input.eof()) {
		std::getline(input, tempstr);
		currpos = 0;
		while (currpos != tempstr.npos) {
			currpos = tempstr.find(argv[2]);
			if (currpos != std::string::npos) {
				std::string	parts = tempstr.substr(0, currpos);
				parts += argv[3];
				parts += tempstr.substr(currpos + strlen(argv[2]), tempstr.npos);
				tempstr = parts;
			}
		}
		output << tempstr;
		if (!input.eof())
			output << std::endl;
	}
	input.close();
	output.close();
}

int	main(int argc, char **argv) {
	std::ifstream	input;
	std::ofstream	output;

	if (inputCheck(argc, argv, input, output) < 0)
		return (1);
	placeAgain(argv, input, output);
}
