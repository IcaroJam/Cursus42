/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:21:37 by senari            #+#    #+#             */
/*   Updated: 2022/11/25 19:36:16 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Cat.hpp"
#include "Dog.hpp"

void	leakCheck(void) {
	system("leaks brainy");
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Creation phase done" << std::endl;

	std::cout << "Var j has type: " << j->getType() << " " << std::endl;
	std::cout << "Var i has type: " << i->getType() << " " << std::endl;
	std::cout << "Var meta has type: " << meta->getType() << " " << std::endl;
	std::cout << "j: "; j->makeSound();
	std::cout << "i: "; i->makeSound(); //will output the cat sound!
	std::cout << "meta: "; meta->makeSound();

	delete j;
	delete i;
	delete meta;

	atexit(leakCheck);

	return 0;
}
