/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:55 by senari            #+#    #+#             */
/*   Updated: 2022/11/24 17:31:33 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cpyFrom);
		Cat &operator=(const Cat &cpyFrom);
		~Cat();

		virtual void	makeSound(void) const;
};

#endif
