/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:05:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/05 12:36:47 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Canonical class shite:
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &givenName, short givenGrade) : _name(givenName), _grade(givenGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &cpyFrom) {
	*this = cpyFrom;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpyFrom) {
	
	return (*this);
}

Bureaucrat::~Bureaucrat() {}
////////////////////////////////////////////////////////////////////////////////
// Member functions:

////////////////////////////////////////////////////////////////////////////////
// Non-member functions:

////////////////////////////////////////////////////////////////////////////////
