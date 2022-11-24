/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:26:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/23 12:01:41 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		void	attack(const std::string &target);
		void	whoAmI(void);

		DiamondTrap();
		DiamondTrap(const std::string &givenName);
		DiamondTrap(const DiamondTrap &cpyFrom);
		DiamondTrap &operator=(const DiamondTrap &cpyfrom);
		~DiamondTrap();

	private:
		std::string	_name;
};

#endif
