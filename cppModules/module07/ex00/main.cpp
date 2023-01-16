/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:35:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/16 12:17:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpletemps.hpp"
#include <iostream>

int	main(void) {
	std::cout << "/// Mandatory ///" << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	std::cout << "/// Extra ///" << std::endl;
	int	i1 = 7, i2 = -12;
	std::cout	<< "i1 = " << i1 << std::endl
				<< "i2 = " << i2 << std::endl
				<< "Swaping: " << std::endl;
	::swap<int>(i1, i2);
	std::cout	<< "i1 = " << i1 << std::endl
				<< "i2 = " << i2 << std::endl
				<< "Min: " << ::min<int>(i1, i2) << std::endl
				<< "Max: " << ::max<int>(i1, i2) << std::endl << std::endl;

	long	ll1 = -467457364534657456, ll2 = 5235346656422512;
	std::cout	<< "ll1 = " << ll1 << std::endl
				<< "ll2 = " << ll2 << std::endl
				<< "Swaping: " << std::endl;
	::swap<long>(ll1, ll2);
	std::cout	<< "ll1 = " << ll1 << std::endl
				<< "ll2 = " << ll2 << std::endl
				<< "Min: " << ::min<long>(ll1, ll2) << std::endl
				<< "Max: " << ::max<long>(ll1, ll2) << std::endl << std::endl;

	const char	*s1 = "test c str1", *s2 = "TesT c sTRinG2";
	std::cout	<< "s1 = " << s1 << std::endl
				<< "s2 = " << s2 << std::endl
				<< "Swaping: " << std::endl;
	::swap<const char *>(s1, s2);
	std::cout	<< "s1 = " << s1 << std::endl
				<< "s2 = " << s2 << std::endl
				<< "Min: " << ::min<const char *>(s1, s2) << std::endl
				<< "Max: " << ::max<const char *>(s1, s2) << std::endl << std::endl;

	std::string	ps1 = "test cpp s1", ps2 = "TesT cPp ps2";
	std::cout	<< "ps1 = " << ps1 << std::endl
				<< "ps2 = " << ps2 << std::endl
				<< "Swaping: " << std::endl;
	::swap<std::string>(ps1, ps2);
	std::cout	<< "ps1 = " << ps1 << std::endl
				<< "ps2 = " << ps2 << std::endl
				<< "Min: " << ::min<std::string>(ps1, ps2) << std::endl
				<< "Max: " << ::max<std::string>(ps1, ps2) << std::endl;
}
