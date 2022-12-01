/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:26:09 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/01 17:36:59 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &cpyFrom);
		MateriaSource &operator=(const MateriaSource &cpyFrom);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria	*createMateria(const std::string &type);

	private:
		AMateria	**_inventory;
		int			_invIndex;
};

#endif
