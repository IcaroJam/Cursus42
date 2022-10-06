/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:33:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/06 12:07:00 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

Account::Account( void ) {

}

Account::Account( int initial_deposit ) {

}

Account::~Account( void ) {

}

int main ( void ) {
	std::time_t	currTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm			currDate = *localtime(&currTime);

	std::cout << currDate.tm_year << std::endl << currDate.tm_mon << std::endl << currDate.tm_mday << std::endl << currDate.tm_hour << std::endl << currDate.tm_min << std::endl << currDate.tm_sec << std::endl;
}
