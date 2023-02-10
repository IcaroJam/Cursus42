/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/02/10 12:25:23 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

void	leaksCheck(void) {
	system("leaks abomination");
}

int main() {
	atexit(leaksCheck);

	MutantStack<int> mstack;
	std::cout << "Created an empty mutant stack." << std::endl;
	mstack.push(5);
	std::cout << "Pushed 5." << std::endl;
	mstack.push(17);
	std::cout << "Pushed 17." << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popped." << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "Pushed 3." << std::endl;
	mstack.push(5);
	std::cout << "Pushed 5." << std::endl;
	mstack.push(737);
	std::cout << "Pushed 737." << std::endl;
	//[...]
	mstack.push(0);
	std::cout << "Pushed 0." << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Printing elements stored:" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nCpystack:" << std::endl;
	MutantStack<int> cpystack(mstack);
	std::cout << "Top: " << cpystack.top() << std::endl;
	std::cout << "Size: " << cpystack.size() << std::endl;

	std::list<int> normalList;
	std::cout << "\nCreated an empty list." << std::endl;
	normalList.push_back(5);
	std::cout << "Pushed 5." << std::endl;
	normalList.push_back(17);
	std::cout << "Pushed 17." << std::endl;
	std::cout << "Back: " << normalList.back() << std::endl;
	normalList.pop_back();
	std::cout << "Popped." << std::endl;
	std::cout << "Size: " << normalList.size() << std::endl;
	normalList.push_back(3);
	std::cout << "Pushed 3." << std::endl;
	normalList.push_back(5);
	std::cout << "Pushed 5." << std::endl;
	normalList.push_back(737);
	std::cout << "Pushed 737." << std::endl;
	//[...]
	normalList.push_back(0);
	std::cout << "Pushed 0." << std::endl;
	std::list<int>::iterator lit = normalList.begin();
	std::list<int>::iterator lite = normalList.end();
	++lit;
	--lit;
	std::cout << "Printing elements stored:" << std::endl;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	return 0;
}
