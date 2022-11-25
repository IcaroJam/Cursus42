/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/25 13:02:29 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Canonical class shite:
ScavTrap::ScavTrap() {
	_model = "ScavTrap";
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Unnamed ScavTrap assembled." << std::endl;
}

ScavTrap::ScavTrap(const std::string &givenName) {
	_model = "ScavTrap";
	_name = givenName;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " assembled." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpyfrom) : ClapTrap()  {
	std::cout << "ScavTrap Copy constructor called." << std::endl;
	*this = cpyfrom;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpyfrom) {
	std::cout << "ScavTrap Copy assignment operator called." << std::endl;
	// This works because both *this and cpyfrom are objects of the same class
	// so they have access to each other's private attributes.
	_name = cpyfrom._name;
	_hitPoints = cpyfrom._hitPoints;
	_energyPoints = cpyfrom._energyPoints;
	_attackDamage = cpyfrom._attackDamage;
	std::cout << "ScavTrap " << _name << " assembled." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
