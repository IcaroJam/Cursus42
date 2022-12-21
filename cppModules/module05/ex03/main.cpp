/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/21 14:02:20 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void leakCheck(void) {
	system("leaks execuForm");
}

int	main(void) {
	atexit(leakCheck);
	
	Intern	UnimportantJake;
	Form	*intForm;

	intForm = UnimportantJake.makeForm("Presidential pardon", "I, myself");

	std::cout << *intForm << std::endl;
}
