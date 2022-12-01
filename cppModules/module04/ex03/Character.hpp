/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:24:45 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 16:57:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(const std::string &givenName);
		Character(const Character &cpyFrom);
		Character &operator=(const Character &cpyFrom);
		~Character();

		virtual const std::string	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	**_inventory;
		int			_invIndex;
};

#endif
