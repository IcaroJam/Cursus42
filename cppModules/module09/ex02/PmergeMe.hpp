/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:07:02 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/14 16:52:23 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
#define PMERGEME

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpyFrom);
		PmergeMe &operator=(const PmergeMe &cpyFrom);
		~PmergeMe();

		int		fillherup(char **argv);
		void	performtest();

	private:
		std::vector<uint32_t>	_vect;
		std::list<uint32_t>		_lst;
		char					**_preSort;

	std::vector<uint32_t>	vectormergeset(std::vector<uint32_t> &vect);
	std::list<uint32_t>		listmergeset(std::list<uint32_t> &lst);
		
};

#endif
