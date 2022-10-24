/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:00:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 16:02:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class	Weapon {
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string	&getType(void) const;
		void		setType(std::string newType);

	private:
		std::string	_type;
};

#endif
