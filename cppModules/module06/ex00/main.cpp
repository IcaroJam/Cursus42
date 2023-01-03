/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:06 by senari            #+#    #+#             */
/*   Updated: 2023/01/03 12:53:08 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <stdio.h>
int	main(int argc, char **argv) {
	if (argc > 1) {
		Converter	DEBUG(argv[1]);
/* 
 *         // Delet dis:
 *         float	testFloat1 = atof(argv[1]);
 *         double	testFloat2 = atof(argv[1]);
 *         printf("float:  %100.100f\ndouble: %100.100f\n", testFloat1, testFloat2);
 *         // Floats seem to hold up to 8 digits of precision, while doubles appear to hold up to 16. These come as a mix of the integer and decimal parts. */
	}
}
