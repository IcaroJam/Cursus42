/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:35:05 by senari            #+#    #+#             */
/*   Updated: 2022/10/19 11:47:45 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*zptr;

	std::cout << "Welcome to the (not)interactive zombie experience.\nPlease proceed with caution :)" << std::endl;
	std::cout << "A good ol' stack fellow named Jack will now be taken out of the vat!" << std::endl;
	randomChump("Jack");
	std::cout << "As you can see Jack was... well, rather short-lived. The stack's demise in cases such as his, without a definite purpose." << std::endl;
	zptr = newZombie("Jeremiah");
	zptr->announce();
	std::cout << "Now would you look at that? Looks like we've got a heap situation in our hands!\n	*Agressively takes a gun and shoots the situation in the head*" << std::endl;
	delete zptr;
	std::cout << "And with that handled, our little tour comes to an end. Thanks for stopping by. Don't come back again." << std::endl;
	return (0);
}
