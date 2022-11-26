/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:48 by senari            #+#    #+#             */
/*   Updated: 2022/11/26 14:23:28 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Canonical class shite:
Brain::Brain() {
	std::cout << "Brain out of the jar and into the animal." << std::endl;
}

Brain::Brain(const Brain &cpyFrom) {
	std::cout << "Creating a new brain from another." << std::endl;
	*this = cpyFrom;
}

Brain &Brain::operator=(const Brain &cpyFrom) {
	std::cout << "Copying a brain\'s content into another." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = cpyFrom.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Performing brain surgery... To the trash it goes!" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
