/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:53:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &cpyFrom);
		Ice &operator=(const Ice &cpyFrom);
		virtual ~Ice();

		virtual Ice		*clone(void) const;
		virtual void	use(ICharacter &target) const;
};

#endif
