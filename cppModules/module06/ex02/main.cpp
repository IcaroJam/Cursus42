/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:49:08 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:51 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	int	rnum = std::rand() % 100;

	if (rnum < 33)
		return (new A);
	else if (rnum < 66)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p) {
	A	*aTry = dynamic_cast<A *>(p);
	if (aTry) {
		std::cout << "Object passed points to type A." << std::endl;
		return;
	}
	B	*bTry = dynamic_cast<B *>(p);
	if (bTry) {
		std::cout << "Object passed points to type B." << std::endl;
		return;
	}
	C	*cTry = dynamic_cast<C *>(p);
	if (cTry)
		std::cout << "Object passed points to type C." << std::endl;
}

void	identify(Base &p) {
	Base	ctry;

	try {
		ctry = dynamic_cast<A &>(p);
		std::cout << "Object passed references type A." << std::endl;
		return;
	} catch (std::bad_cast &bc) {}
	try {
		ctry = dynamic_cast<B &>(p);
		std::cout << "Object passed references type B." << std::endl;
		return;
	} catch (std::bad_cast &bc) {}
	try {
		ctry = dynamic_cast<C &>(p);
		std::cout << "Object passed references type C." << std::endl;
		return;
	} catch (std::bad_cast &bc) {}
}

void	leakCheck(void) {
	system("leaks identifierGlass");
}

int	main(void) {
	atexit(leakCheck);
	std::srand(std::time(NULL));

	for (int i = 0; i < 27; i++) {
		Base *temp = generate();
		identify(temp);
		identify(*temp);
		std::cout << std::endl;
		delete temp;
	}
}
