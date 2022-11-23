/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:37:23 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/23 11:56:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Canonical class shite:
DiamondTrap::DiamondTrap() {
	_model = "DiamondTrap";
	_name = "Unnamed";
	ClapTrap::_name = "Unnamed_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "Unnamed DiamondTrap assembled." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &givenName) {
	_model = "DiamondTrap";
	_name = givenName;
	ClapTrap::_name = givenName + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " assembled." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpyfrom) {
	std::cout << "DiamondTrap Copy constructor called." << std::endl;
	*this = cpyfrom;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpyfrom) {
	std::cout << "DiamondTrap Copy assignment operator called." << std::endl;
	// This works because both *this and cpyfrom are objects of the same class
	// so they have access to each other's private attributes.
	_name = cpyfrom._name;
	_hitPoints = cpyfrom._hitPoints;
	_energyPoints = cpyfrom._energyPoints;
	_attackDamage = cpyfrom._attackDamage;
	std::cout << "DiamondTrap " << _name << " assembled." << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap " << _name << " reporting. Clap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
	std::cout << ">> Attacking from DiamondTrap" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
