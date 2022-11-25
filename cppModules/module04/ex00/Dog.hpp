/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:55 by senari            #+#    #+#             */
/*   Updated: 2022/11/24 17:32:11 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &cpyFrom);
		Dog &operator=(const Dog &cpyFrom);
		~Dog();

		virtual void	makeSound(void) const;
};

#endif
