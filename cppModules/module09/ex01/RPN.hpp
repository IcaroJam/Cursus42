/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/13 11:40:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN
#define RPN

#include <stack>
#include <iostream>

class Rpn {
	public:
		Rpn();
		Rpn(const Rpn &cpyFrom);
		Rpn &operator=(const Rpn &cpyFrom);
		~Rpn();

		int	printResult(const char *op);

	private:
		std::stack<int>	_stck;
};

#endif
