/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:54 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:10:12 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Canonical class shite:
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("noTarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string givenTarget) : Form("RobotomyRequestForm", 72, 45), _target(givenTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpyFrom) : Form(cpyFrom) {
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
	Form::execute(executor);
	std::cout << "*drilling and tuning noises*" << std::endl;
	std::srand(std::time(NULL));
	size_t DEBUGRAND = std::rand();
	std::cout << "DEBUG: Random number generated is " << DEBUGRAND << std::endl;
	if (DEBUGRAND % 2)
		std::cout << _target << " was successfuly robotomized!" << std::endl;
	else
		std::cout << "Failed to robotimize " << _target << " :(" << std::endl;
}

Form	*RobotomyRequestForm::clone(std::string givenTarget) {return (new RobotomyRequestForm(givenTarget));}
////////////////////////////////////////////////////////////////////////////////
