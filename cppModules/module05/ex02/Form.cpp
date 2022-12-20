/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:05:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/20 13:45:33 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Exception definitions:
class Form::gradeTooHighException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("An error ocurred while initializing a Form class instance (Form::gradeTooHighException)\n");
		}
};

class Form::gradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("An error ocurred while initializing a Form class instance (Form::gradeTooLowException)\n");
		}
};

class Form::unsignedFormException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("An error ocurred while executing a Form class instance derived class instance (Form::unsignedFormException)\n");
		}
};
////////////////////////////////////////////////////////////////////////////////
// Canonical class shite:
Form::Form() : _name("Unnamed"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &givenName, short givenSignGrade, short givenExecGrade) : _name(givenName), _signed(false) {
	if (givenSignGrade < 1 || givenExecGrade < 1)
		throw gradeTooHighException();
	else if (givenSignGrade > 150 || givenExecGrade > 150)
		throw gradeTooLowException();
	_signGrade = givenSignGrade;
	_execGrade = givenExecGrade;
}

Form::Form(const Form &cpyFrom) : _name(cpyFrom._name) {
	*this = cpyFrom;
}

Form &Form::operator=(const Form &cpyFrom) {
	_signed = cpyFrom._signed;
	_signGrade = cpyFrom._signGrade;
	_execGrade = cpyFrom._execGrade;
	return (*this);
}

Form::~Form() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:
std::string	Form::getName(void) const {return (_name);}

bool		Form::getSignStatus(void) const {return (_signed);}

short		Form::getSignGrade(void) const {return (_signGrade);}

short		Form::getExecGrade(void) const {return (_execGrade);}

void		Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() <= _signGrade)
		_signed = true;
	else
		throw gradeTooLowException();
}

void		Form::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw unsignedFormException();
	if (executor.getGrade() > _execGrade)
		throw gradeTooLowException();
}
////////////////////////////////////////////////////////////////////////////////
// Non-member functions:
std::ostream	&operator<<(std::ostream &outstream, const Form &form) {
	outstream << "Form \"" << form.getName() << "\", sign state: ";
	form.getSignStatus() ? outstream << "signed. " : outstream << "unsigned. ";
	outstream << "Signing grade: " << form.getSignGrade() << ". Executing grade: " << form.getExecGrade() << ".";
	return (outstream);
}
////////////////////////////////////////////////////////////////////////////////
