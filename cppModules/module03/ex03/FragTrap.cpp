/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:14:00 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/23 12:00:14 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Canonical class shite:
FragTrap::FragTrap() {
	_model = "FragTrap";
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Unnamed FragTrap assembled." << std::endl;
}

FragTrap::FragTrap(const std::string &givenName) {
	_model = "FragTrap";
	_name = givenName;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " assembled." << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpyfrom) {
	std::cout << "FragTrap Copy constructor called." << std::endl;
	*this = cpyfrom;
}

FragTrap &FragTrap::operator=(const FragTrap &cpyfrom) {
	std::cout << "FragTrap Copy assignment operator called." << std::endl;
	// This works because both *this and cpyfrom are objects of the same class
	// so they have access to each other's private attributes.
	_name = cpyfrom._name;
	_hitPoints = cpyfrom._hitPoints;
	_energyPoints = cpyfrom._energyPoints;
	_attackDamage = cpyfrom._attackDamage;
	std::cout << "FragTrap " << _name << " assembled." << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << ": Up high bois! :D" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	ClapTrap::attack(target);
	std::cout << ">> Attacking from FragTrap" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
