/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:54 by senari            #+#    #+#             */
/*   Updated: 2022/12/20 17:09:14 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Canonical class shite:
ShrubberyCreationForm::ShrubberyCreationForm() : _target("noTarget"), Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string givenTarget) : _target(givenTarget), Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpyFrom) {
	*this = cpyFrom;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpyFrom) {
	_target = cpyFrom._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::ofstream	outfile;

	outfile.open(_target + "_shrubbery");
	if (outfile.fail()) {
		std::cerr << "Failed to create the outfile." << std::endl;
		exit(1);
	}
	Form::execute(executor);
	outfile << "*tree*\n_tree_\n*tree*\n(ascii fucked the editor up lol)" << std::endl;
	outfile.close();
}
////////////////////////////////////////////////////////////////////////////////
