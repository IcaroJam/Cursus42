/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:07:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/23 11:59:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		void	attack(const std::string &target);
		void	guardGate(void);

		ScavTrap();
		ScavTrap(const std::string &givenName);
		ScavTrap(const ScavTrap &cpyfrom);
		ScavTrap &operator=(const ScavTrap &cpyfrom);
		~ScavTrap();
};

#endif
