/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:06 by senari            #+#    #+#             */
/*   Updated: 2022/12/27 13:09:05 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <limits.h>
int	main(int argc, char **argv) {
	if (argc > 1) {
		// do stuff for each string on argv. Maybe create a Converter instance and print with it?
		int i = 0;
		while (i < INT_MAX) {
			std::cout << i << ": " << isprint(i) << std::endl;
			i++;
		}
		return 0;
		Converter	DEBUG(argv[1]);
	}
}
