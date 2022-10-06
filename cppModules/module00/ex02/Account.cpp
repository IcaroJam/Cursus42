/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:33:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/10/06 15:50:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>

/////Static init////////////////////////////////////////////////////////////////
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/////Constructors///////////////////////////////////////////////////////////////
Account::Account( void ) : _accountIndex(_nbAccounts++), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:0;created" << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << initial_deposit
		<< ";created" << std::endl;
}

/////Destructor/////////////////////////////////////////////////////////////////
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

/////Displaying/////////////////////////////////////////////////////////////////
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	currTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm			currDate = *localtime(&currTime);

	std::cout << "[" << std::setfill('0') 
		<< currDate.tm_year + 1900
		<< std::setw(2) << currDate.tm_mon + 1
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
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {return _amount;}
