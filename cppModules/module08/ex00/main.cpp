/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:46:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/17 16:05:18 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename T> void	test(T &cont, int num) {
	typename T::iterator	tempiter = cont.begin();

	std::cout << "Elements in container: ";
	for (; tempiter != cont.end(); ++tempiter) {
		std::cout << *tempiter << " ";
	}
	tempiter = easyfind(cont, num);
	if (tempiter == cont.end()) 
		std::cout << "\nElement " << num << " couldn't be found." << std::endl;
	else
		std::cout << "\nElement pointed to by the iterator returned by easyfind: " << *tempiter << std::endl;
}

int	main(void) {
	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	std::cout << "Empty vector:\n";
	test(v, 4);
	std::cout << "Empty list:\n";
	test(l, -12);
	std::cout << "Empty deque:\n";
	test(d, 0);

	std::cout << "\nPushing elements into containers..." << std::endl;
	v.push_back(12); v.push_back(0); v.push_back(-5432); v.push_back(7);
	l.push_back(-1); l.push_back(87546); l.push_back(-427);
	d.push_back(6); d.push_back(-412); d.push_back(4); d.push_back(0); d.push_back(1234);

	test(v, 4);
	test(l, -12);
	test(d, 1);

	std::cout << "\nLet's try to find values that can be found." << std::endl;
	test(v, 7);
	test(l, -1);
	test(d, 0);
}
