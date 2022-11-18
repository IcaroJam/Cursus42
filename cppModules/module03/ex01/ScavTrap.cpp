/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/18 13:44:52 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Canonical class shite:
ScavTrap::ScavTrap() {
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Unnamed ScavTrap assembled." << std::endl;
}

ScavTrap::ScavTrap(std::string givenName) {
	_name = givenName;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " assembled." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpyfrom) {
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
void	ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target
				  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " failed to attack " << target << "!" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " hitpoints!" << "(Current: " << _hitPoints << ")" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " failed to repair itself!" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (!_hitPoints) {
		std::cout << "ScavTrap " << _name << " already has 0 hitpoints!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << "(Current: " << _hitPoints << ")" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
