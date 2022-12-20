/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/20 19:38:50 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leakCheck(void) {
	system("leaks execuForm");
}

int	main(void) {
	atexit(leakCheck);

	Bureaucrat	shrubBuro("Bill", 146), roboBuro("Alec", 73), presiBuro("Barack", 26);
	Bureaucrat	shrubExec("Dr. Bill", 138), roboExec("Dr. Alec", 46), presiExec("Dr. Barack", 6);
	Form		*shrubForm = new ShrubberyCreationForm("Aparto");
	Form		*roboForm = new RobotomyRequestForm("cyber-Mike");
	Form		*presiForm = new PresidentialPardonForm("GigaCryminal");

	std::cout << "Form states:\n";
	std::cout << *shrubForm << std::endl;
	std::cout << *roboForm << std::endl;
	std::cout << *presiForm << std::endl << std::endl;

	std::cout << "Attempting to sign forms:" << std::endl;
	std::cout << shrubBuro << std::endl;
	shrubBuro.signForm(shrubForm);
	std::cout << roboBuro << std::endl;
	roboBuro.signForm(roboForm);
	std::cout << presiBuro << std::endl;
	presiBuro.signForm(presiForm);
	
	std::cout << "Increasing grades by 1:" << std::endl;
	shrubBuro.gradeInc();
	std::cout << shrubBuro << std::endl;
	roboBuro.gradeInc();
	std::cout << roboBuro << std::endl;
	presiBuro.gradeInc();
	std::cout << presiBuro << std::endl << std::endl;

	std::cout << "Attempting to sign forms:" << std::endl;
	shrubBuro.signForm(shrubForm);
	roboBuro.signForm(roboForm);
	presiBuro.signForm(presiForm);

	std::cout << "\nForm states:\n";
	std::cout << *shrubForm << std::endl;
	std::cout << *roboForm << std::endl;
	std::cout << *presiForm << std::endl << std::endl;

	std::cout << "Attempting to execute forms:" << std::endl;
	std::cout << shrubExec << std::endl;
	shrubExec.execForm(*shrubForm);
	std::cout << roboExec << std::endl;
	roboExec.execForm(*roboForm);
	std::cout << presiExec << std::endl;
	presiExec.execForm(*presiForm);
	
	std::cout << "Increasing grades by 1:" << std::endl;
	shrubExec.gradeInc();
	std::cout << shrubExec << std::endl;
	roboExec.gradeInc();
	std::cout << roboExec << std::endl;
	presiExec.gradeInc();
	std::cout << presiExec << std::endl << std::endl;

	std::cout << "Attempting to exec forms:" << std::endl;
	shrubExec.execForm(*shrubForm);
	roboExec.execForm(*roboForm);
	presiExec.execForm(*presiForm);
}
