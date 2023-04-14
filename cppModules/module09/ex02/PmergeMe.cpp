/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:09:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/04/14 13:22:36 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Aid functions:
bool	betteratoi(const char *str, uint32_t &num) {
	if (std::strlen(str) > 10)
		return true;
	num = 0;
	for (uint32_t i = 0; str[i]; i++) {
		num *= 10;
		num += str[i] - '0';
		if (num > (uint32_t)std::numeric_limits<int>::max())
			return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
// Canonical class shite:
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpyFrom) {
	*this = cpyFrom;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpyFrom) {
	_lst = cpyFrom._lst;
	_vect = cpyFrom._vect;
	_preSort = cpyFrom._preSort;
	return (*this);
}

PmergeMe::~PmergeMe() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
int		PmergeMe::fillherup(char **argv) {
	_preSort = argv;
	for (uint32_t i = 0; argv[i]; i++) {
		uint32_t	temp;
		if (betteratoi(argv[i], temp)) {
			std::cerr << "Error: Argument '" << argv[i] << "' overflows the int." << std::endl;
			return (1);
		}
		_vect.push_back(temp);
		_lst.push_back(temp);
	}
	return (0);
}

// Redefine this little shits so I can not write it over and over again :)
typedef std::vector<uint32_t>::iterator vit;
typedef std::list<uint32_t>::iterator lit;

std::vector<uint32_t>	PmergeMe::vectormergeset(std::vector<uint32_t> &vect, uint32_t start, uint32_t end) {
	// Insert sort for vectors smaller than 11 elements:
	if ((end - start) <= 10) {
        for (uint32_t i = 1; i < vect.size(); i++) {
			uint32_t	lookback = i;
			uint32_t	movable = vect[i];

			while (lookback > 0 && vect[lookback - 1] > movable) {
				vect[lookback] = vect[lookback - 1];
				lookback--;
			}
			vect[lookback] = movable;
        }
		return (vect);
	}

	// Merge sort (recursivity, yay):
	vit						goldenMean = vect.begin() + vect.size() / 2;
	std::vector<uint32_t>	left(vect.begin(), goldenMean);
	std::vector<uint32_t>	right(goldenMean, vect.end());

	left = vectormergeset(left, 0, left.size());
	right = vectormergeset(right, 0, right.size());
	// Merge that shit:
	std::vector<uint32_t>	merged;
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
	return (merged);
}

std::list<uint32_t>	PmergeMe::listmergeset(std::list<uint32_t> &lst, uint32_t start, uint32_t end) {
	// Insert sort for lists smaller than 11 elements:
	if ((end - start) <= 10) {
        for (lit i = ++lst.begin(); i != lst.end();) {
			lit	lookback = i;
			std::advance(lookback, -1);

			while (lookback != lst.begin() && *lookback > *i)
				--lookback;
			if (*lookback < *i)
				++lookback;
			if (*lookback >= *i) {
				lst.insert(lookback, *i);
				i = lst.erase(i);
			} else {
				++i;
			}
        }
		return (lst);
	}

	// Merge sort (recursivity, yay):
	lit						goldenMean = lst.begin();
	std::advance(goldenMean, std::distance(lst.begin(), lst.end()) / 2);
	std::list<uint32_t>	left(lst.begin(), goldenMean);
	std::list<uint32_t>	right(goldenMean, lst.end());

	left = listmergeset(left, 0, left.size());
	right = listmergeset(right, 0, right.size());
	// Merge that shit:
	std::list<uint32_t>	merged;
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
	return (merged);
}

void	PmergeMe::performtest() {
	std::cout << "Before:   ";
	for (uint32_t i = 0; _preSort[i]; i++)
		std::cout << " " << _preSort[i];
	std::cout << std::endl;

	// Measure initial time.
	std::clock_t	vstart = clock();
	std::clock_t	lstart = clock();
	// Do the sorting.
	_vect = vectormergeset(_vect, 0, _vect.size());
	_lst = listmergeset(_lst, 0, _lst.size());
	// Measure final time.
	std::clock_t	vend = clock();
	std::clock_t	lend = clock();

	std::cout << "After (V):";
	for (uint32_t i = 0; i < _vect.size(); i++)
		std::cout << " " << _vect[i];
	std::cout << std::endl;

	std::cout << "After (L):";
	for (lit i = _lst.begin(); i != _lst.end(); ++i)
		std::cout << " " << *i;
	std::cout << std::endl;

	// Print the rest of the stuff.
	double	vellapsed = (double)(vend - vstart) * 1.e6 / CLOCKS_PER_SEC;
	double	lellapsed = (double)(lend - lstart) * 1.e6 / CLOCKS_PER_SEC;
	std::cout.precision(5);
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector<uint32_t>" << " : " << vellapsed << " us" << std::endl;
	std::cout << "Time to process a range of " << _lst.size() << " elements with std::list<uint32_t>" << "   : " << lellapsed << " us" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
