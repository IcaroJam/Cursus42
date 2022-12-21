/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:29 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:03:06 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string givenTarget);
		PresidentialPardonForm(const PresidentialPardonForm &cpyFrom);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &cpyFrom);
		virtual ~PresidentialPardonForm();

		void execute(const Bureaucrat &executor) const;
		static Form *clone(std::string givenTarget);

	private:
		std::string	_target;
};

#endif
