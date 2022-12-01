/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:15:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 18:21:28 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Canonical class shite:
Character::Character() : _name("Unnamed Character"), _invIndex(0) {
	_inventory = new AMateria*[4];
}

Character::Character(const std::string &givenName) : _name(givenName), _invIndex(0) {
	_inventory = new AMateria*[4];
}

Character::Character(const Character &cpyFrom) {
	*this = cpyFrom;
}

Character &Character::operator=(const Character &cpyFrom) {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	delete [] _inventory;
	_name = cpyFrom._name;
	_invIndex = cpyFrom._invIndex;
	_inventory = new AMateria*[4];
	for (int i = 0; i < cpyFrom._invIndex; i++)
		_inventory[i] = cpyFrom._inventory[i];
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	delete [] _inventory;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
const std::string	&Character::getName(void) const {
	return (_name);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			_invIndex++;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx > -1 && idx < 4 && _inventory[idx]) {
		_inventory[idx] = NULL;
		_invIndex--;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx > -1 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
}
////////////////////////////////////////////////////////////////////////////////
