/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:13 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/19 19:36:19 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Form.hpp"

void leakCheck(void) {
	system("leaks formMeThis");
}

int	main(void) {
	atexit(leakCheck);

	Bureaucrat	buro("Bill", 65);
	Form		form1, form2("F17, Fox Adoption", 64, 64);

	try {
		std::cout << "Attempting to initialize bad form: ";
		Form	form3("Fail Form", 151, 1);
	} catch(std::exception &exep) {
		std::cout << exep.what() << std::endl;
	}

	std::cout << form2 << std::endl << "Buro Bill will attempt to sign form: " << form2.getName() << std::endl;

	buro.signForm(&form2);

	std::cout << "Increasing Bill's grade and attempting again." << std::endl;

	buro.gradeInc();
	buro.signForm(&form2);

	std::cout << form2 << std::endl;
}
