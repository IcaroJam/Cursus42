/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:29 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:03:22 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <stdlib.h>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string givenTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpyFrom);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpyFrom);
		virtual ~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
		static Form *clone(std::string givenTarget);

	private:
		std::string	_target;
};

#endif
