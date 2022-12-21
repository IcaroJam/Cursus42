/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:33:35 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:09:00 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string validForms[] = {
	"SHRUBBERY CREATION",
	"SHRUBBERYCREATION",
	"SHRUBBERYCREATIONFORM",
	"ROBOTOMY REQUEST",
	"ROBOTOMYREQUEST",
	"ROBOTOMYREQUESTFORM",
	"PRESIDENTIAL PARDON",
	"PRESIDENTIALPARDON",
	"PRESIDENTIALPARDONFORM",
	""
};

Form	*(*Intern::_formPtrs[])(std::string) = {
	ShrubberyCreationForm::clone,
	RobotomyRequestForm::clone,
	PresidentialPardonForm::clone
};

// Canonical class shite:
Intern::Intern() {}

Intern::Intern(const Intern &cpyFrom) {(void)cpyFrom;}

Intern &Intern::operator=(const Intern &cpyFrom) {(void)cpyFrom; return (*this);}

Intern::~Intern() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
Form	*Intern::makeForm(std::string formName, const std::string &formTarget) {
	for (std::string::size_type i = 0; i < formName.length(); i++)
		formName[i] = std::toupper(formName[i]); // Standarize the input to upper case.
	
	for (int i = 0; validForms[i] != ""; i++) {
		if (formName == validForms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (_formPtrs[i / 3](formTarget));
		}
	}
	std::cerr << "Intern couldn't find references for " << formName << std::endl;
	return (NULL);
}
////////////////////////////////////////////////////////////////////////////////
