/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:55 by senari            #+#    #+#             */
/*   Updated: 2022/11/26 14:27:07 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpyFrom);
		WrongAnimal &operator=(const WrongAnimal &cpyFrom);
		virtual ~WrongAnimal();

		std::string		getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
