/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:53:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:53:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cpyFrom);
		Cure &operator=(const Cure &cpyFrom);
		virtual ~Cure();

		virtual Cure		*clone(void) const;
		virtual void	use(ICharacter &target) const;
};

#endif
