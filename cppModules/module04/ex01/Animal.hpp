/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:55 by senari            #+#    #+#             */
/*   Updated: 2022/11/25 09:14:54 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal {
	public:
		Animal();
		Animal(const Animal &cpyFrom);
		Animal &operator=(const Animal &cpyFrom);
		virtual ~Animal();

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
