/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:06:11 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/20 13:46:58 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string &givenName, short givenGrade);
		Bureaucrat(const Bureaucrat &cpyFrom);
		Bureaucrat &operator=(const Bureaucrat &cpyFrom);
		~Bureaucrat();

		std::string	getName(void) const;
		short		getGrade(void) const;

		void		gradeInc(void);
		void		gradeDec(void);

		void		signForm(Form *form);
		void		execForm(const Form &form) const;

	private:
		const std::string	_name;
		short				_grade;

		class				gradeTooHighException;
		class				gradeTooLowException;
};

std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &buro);

#endif
