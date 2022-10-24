/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:13:00 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/24 12:21:49 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	myStr = "HI THIS IS BRAIN";
	std::string	*stringPTR = &myStr;
	std::string	&stringREF = myStr;

	std::cout	<< "ADDRESSES:" << std::endl
				<< "myStr: " << &myStr << std::endl
				<< "stringPTR: " << stringPTR << std::endl
				<< "stringREF: " << &stringREF << std::endl
				<< "VALUES:" << std::endl
				<< "myStr: " << myStr << std::endl
				<< "stringPTR: " << *stringPTR << std::endl
				<< "stringREF: " << stringREF << std::endl;
}
