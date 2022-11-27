/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:21:37 by senari            #+#    #+#             */
/*   Updated: 2022/11/27 13:07:22 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Cat.hpp"
#include "Dog.hpp"

void	leakCheck(void) {
	system("leaks brainy");
}

int main()
{
	const Animal	*animalArr[10];

	for (int i = 0; i < 5; i++)
		animalArr[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animalArr[i] = new Dog();

	std::cout << "animalArr[3] (" << animalArr[3]->getType() << "): " << std::endl; animalArr[3]->makeSound();
	std::cout << "animalArr[7] (" << animalArr[7]->getType() << "): " << std::endl; animalArr[7]->makeSound();

	for (int i = 0; i < 10; i++)
		delete animalArr[i];

	atexit(leakCheck);

	return 0;
}
