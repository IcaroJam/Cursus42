/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/18 13:45:29 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Canonical class shite:
ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Unnamed ClapTrap assembled." << std::endl;
}

ClapTrap::ClapTrap(std::string givenName) : _name(givenName), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " assembled." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpyfrom) {
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = cpyfrom;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpyfrom) {
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	// This works because both *this and cpyfrom are objects of the same class
	// so they have access to each other's private attributes.
	_name = cpyfrom._name;
	_hitPoints = cpyfrom._hitPoints;
	_energyPoints = cpyfrom._energyPoints;
	_attackDamage = cpyfrom._attackDamage;
	std::cout << "ClapTrap " << _name << " assembled." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target
				  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " failed to attack " << target << "!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hitpoints!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " failed to repair itself!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " already has 0 hitpoints!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
