/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/17 13:59:24 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Unnamed ClapTrap assembled." << std::endl;
}

ClapTrap::ClapTrap(std::string givenName) : _name(givenName), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " assembled." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpyfrom) {
	std::cout << "Copy constructor called." << std::endl;
	*this = cpyfrom;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpyfrom) {
	std::cout << "Copy assignment operator called." << std::endl;
	// This works because both *this and cpyfrom are objects of the same class
	// so they have access to each other's private attributes.
	_name = cpyfrom._name;
	_hitPoints = cpyfrom._hitPoints;
	_energyPoints = cpyfrom._energyPoints;
	_attackDamage = cpyfrom._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}
