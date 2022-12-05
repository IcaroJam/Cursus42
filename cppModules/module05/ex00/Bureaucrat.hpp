/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:06:11 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/05 15:27:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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

	private:
		const std::string	_name;
		short				_grade;

		class				gradeTooHighException;
		class				gradeTooLowException;
};

std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &buro);

#endif
