/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:29:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB(void);

		void	setWeapon(Weapon &nuWpn);
		void	attack(void);

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
