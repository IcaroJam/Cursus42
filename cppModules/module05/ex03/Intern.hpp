/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:24:56 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 13:56:34 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &cpyFrom);
		Intern &operator=(const Intern &cpyFrom);
		~Intern();

		Form	*makeForm(std::string formName, const std::string &formTarget);

	private:
		static Form	*(*_formPtrs[])(std::string);
};

#endif
