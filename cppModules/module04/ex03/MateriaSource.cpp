/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:32:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 17:47:40 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Canonical class shite:
MateriaSource::MateriaSource() : _invIndex(0) {
	_inventory = new AMateria*[4];
}

MateriaSource::MateriaSource(const MateriaSource &cpyFrom) {
	*this = cpyFrom;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpyFrom) {
	delete [] _inventory;
	_invIndex = cpyFrom._invIndex;
	_inventory = new AMateria*[4];
	for (int i = 0; i < cpyFrom._invIndex; i++)
		_inventory[i] = cpyFrom._inventory[i];
	return (*this);
}

MateriaSource::~MateriaSource() {
	delete [] _inventory;
}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	MateriaSource::learnMateria(AMateria *m) {
	if (_invIndex > 3) {
		delete m;
		return;
	}
	_inventory[_invIndex] = m;
	_invIndex++;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < _invIndex; i++) {
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}
////////////////////////////////////////////////////////////////////////////////
