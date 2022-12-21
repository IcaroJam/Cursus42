/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/21 14:14:05 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void leakCheck(void) {
	system("leaks execuForm");
}

int	main(void) {
	atexit(leakCheck);
	
	Bureaucrat	ImportantBuro("Jeremiah", 3);
	Intern		UnimportantJake;
	Form		*intForm;

	intForm = UnimportantJake.makeForm("PresidentialpardonfOrm", "I, myself");

	std::cout << *intForm << std::endl;
	ImportantBuro.signForm(intForm);
	ImportantBuro.execForm(*intForm);

	delete intForm;
}
