/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:06 by senari            #+#    #+#             */
/*   Updated: 2022/12/26 19:34:01 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int argc, char **argv) {
	if (argc > 1) {
		// do stuff for each string on argv. Maybe create a Converter instance and print with it?
		Converter	DEBUG(argv[1]);
	}
}
