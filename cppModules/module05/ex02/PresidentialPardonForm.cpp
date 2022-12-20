/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:54 by senari            #+#    #+#             */
/*   Updated: 2022/12/20 18:01:56 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Canonical class shite:
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("noTarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string givenTarget) : Form("PresidentialPardonForm", 25, 5), _target(givenTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpyFrom) : Form(cpyFrom) {
	*this = cpyFrom;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpyFrom) {
	_target = cpyFrom._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
