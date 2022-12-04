/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:45:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/04 12:45:07 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	leakCheck(void) {
	system("leaks materials");
}

int	main(void) {
	atexit(leakCheck);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* mat1;
	AMateria* mat2;
	mat1 = src->createMateria("ice");
	me->equip(mat1);
	mat2 = src->createMateria("cure");
	me->equip(mat2);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(2);
	me->unequip(1);
	me->use(1, *bob);
	me->unequip(0);

	delete mat1;
	delete mat2;

	delete bob;
	delete me;
	delete src;

	return 0;
}
