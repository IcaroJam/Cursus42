/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:19:21 by senari            #+#    #+#             */
/*   Updated: 2022/10/24 11:41:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie {
	public:
		void announce(void) const;
		void setName(std::string name);

		Zombie(std::string name);
		Zombie(void);
		~Zombie();

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
