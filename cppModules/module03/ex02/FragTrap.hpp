/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:03:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/11/21 13:13:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		void	highFivesGuys(void);

		FragTrap();
		FragTrap(const std::string &givenName);
		FragTrap(const FragTrap &cpyFrom);
		FragTrap &operator=(const FragTrap &cpyfrom);
		~FragTrap();
};

#endif
