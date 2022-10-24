/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:29:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 16:04:14 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	setWeapon(Weapon &nuWpn);
		void	attack(void);

	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif
