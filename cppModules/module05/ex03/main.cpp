/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/26 12:59:53 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void leakCheck(void) {
	system("leaks internsInternsInterns");
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
