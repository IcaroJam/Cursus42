/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:54 by senari            #+#    #+#             */
/*   Updated: 2022/12/20 17:19:04 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Canonical class shite:
RobotomyRequestForm::RobotomyRequestForm() : _target("noTarget"), Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string givenTarget) : _target(givenTarget), Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpyFrom) {
	*this = cpyFrom;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpyFrom) {
	_target = cpyFrom._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	std::cout << "*drilling and tuning noises*" << std::endl;
	size_t DEBUGRAND = std::rand();
	std::cout << "DEBUG: Random number generated is " << DEBUGRAND << std::endl;
	if (DEBUGRAND % 2)
		std::cout << _target << "was successfuly robotomized!" << std::endl;
	else
		std::cout << "Failed to robotimize " << _target << " :(" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
