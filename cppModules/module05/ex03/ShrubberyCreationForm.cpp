/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:54 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:09:56 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Canonical class shite:
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("noTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string givenTarget) : Form("ShrubberyCreationForm", 145, 137), _target(givenTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpyFrom) : Form(cpyFrom) {
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

	Form::execute(executor);
	outfile.open((_target + "_shrubbery").c_str());
	if (outfile.fail()) {
		std::cerr << "Failed to create the outfile." << std::endl;
		exit(1);
	}
	outfile << "*tree*\n_tree_\n*tree*\n(ascii fucked the editor up lol)" << std::endl;
	outfile.close();
}

Form	*ShrubberyCreationForm::clone(std::string givenTarget) {return (new ShrubberyCreationForm(givenTarget));}
////////////////////////////////////////////////////////////////////////////////
