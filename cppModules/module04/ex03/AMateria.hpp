/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:42:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:52:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria {
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &cpyFrom);
		AMateria &operator=(const AMateria &cpyFrom);
		virtual ~AMateria();

		const std::string &getType(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target) const;

	protected:
		std::string	_type;
};

#endif
