/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:19:01 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/19 11:04:17 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T> class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>();
		MutantStack<T>(const MutantStack &cpyFrom);
		MutantStack<T> &operator=(const MutantStack &cpyFrom);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif
