/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:06:11 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/20 20:21:26 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(const std::string &givenName, short givenSignGrade, short givenExecGrade);
		Form(const Form &cpyFrom);
		Form &operator=(const Form &cpyFrom);
		virtual ~Form();

		std::string			getName(void) const;
		bool				getSignStatus(void) const;
		short				getSignGrade(void) const;
		short				getExecGrade(void) const;

		void				beSigned(const Bureaucrat &signer);
		virtual void		execute(const Bureaucrat &executor) const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		short				_signGrade;
		short				_execGrade;

		class				gradeTooHighException;
		class				gradeTooLowException;
		class				unsignedFormException;
};

std::ostream	&operator<<(std::ostream &outstream, const Form &form);

#endif
