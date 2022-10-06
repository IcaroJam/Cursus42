/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:33:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/06 13:03:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>

/////Constructors///////////////////////////////////////////////////////////////
Account::Account( void ) {
}

Account::Account( int initial_deposit ) {
}

/////Destructor/////////////////////////////////////////////////////////////////
Account::~Account( void ) {
}

/////Displaying/////////////////////////////////////////////////////////////////
void	Account::displayAccountsInfos( void ) {
	
}

void	Account::displayStatus( void ) const {
	
}

void	Account::_displayTimestamp( void ) {
	std::time_t	currTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm			currDate = *localtime(&currTime);

	std::cout << "[" << std::setfill('0') 
		<< currDate.tm_year + 1900
		<< std::setw(2) << currDate.tm_mon
		<< std::setw(2) << currDate.tm_mday
		<< "_"
		<< std::setw(2) << currDate.tm_hour
		<< std::setw(2) << currDate.tm_min
		<< std::setw(2) << currDate.tm_sec
		<< "] ";
}

/////Getters////////////////////////////////////////////////////////////////////
int	Account::getNbAccounts( void ) {return _nbAccounts;}

int	Account::getTotalAmount( void ) {return _totalAmount;}

int	Account::getNbDeposits( void ) {return _totalNbDeposits;}

int	Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

/////Setters////////////////////////////////////////////////////////////////////
void	Account::makeDeposit(int deposit) {
	
}

bool	Account::makeWithdrawal(int withdrawal) {
	return true;
}

int		Account::checkAmount( void ) const {
	return 0;
}
