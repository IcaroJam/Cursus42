/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:29 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 14:03:44 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string givenTarget);
		RobotomyRequestForm(const RobotomyRequestForm &cpyFrom);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpyFrom);
		virtual ~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
		static Form *clone(std::string givenTarget);

	private:
		std::string	_target;
};

#endif
