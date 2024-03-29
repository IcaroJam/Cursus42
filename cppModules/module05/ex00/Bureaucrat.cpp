/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:05:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/05 16:02:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Exception definitions:
class Bureaucrat::gradeTooHighException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("An error ocurred while initializing a Bureaucrat class instance (Bureaucrat::gradeTooHighException)\n");
		}
};

class Bureaucrat::gradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("An error ocurred while initializing a Bureaucrat class instance (Bureaucrat::gradeTooLowException)\n");
		}
};
////////////////////////////////////////////////////////////////////////////////
// Canonical class shite:
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &givenName, short givenGrade) : _name(givenName) {
	if (givenGrade < 1)
		throw gradeTooHighException();
	else if (givenGrade > 150)
		throw gradeTooLowException();
	_grade = givenGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpyFrom) : _name(cpyFrom._name) {
	*this = cpyFrom;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpyFrom) {
	_grade = cpyFrom._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
std::string	Bureaucrat::getName(void) const {return (_name);}

short		Bureaucrat::getGrade(void) const {return (_grade);}

void		Bureaucrat::gradeInc(void) {
	if (_grade == 1)
		throw gradeTooHighException();
	_grade--;
}

void		Bureaucrat::gradeDec(void) {
	if (_grade == 150)
		throw gradeTooLowException();
	_grade++;
}
////////////////////////////////////////////////////////////////////////////////
// Non-member functions:
std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &buro) {
	outstream << buro.getName() << ", bureaucrat grade " << buro.getGrade() << ".";
	return (outstream);
}
////////////////////////////////////////////////////////////////////////////////
