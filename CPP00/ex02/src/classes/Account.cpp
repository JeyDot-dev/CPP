/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:55:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 14:46:10 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";pamount:" << this->_amount << ";deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";pamount:" << this->checkAmount() << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return true;
}

int	Account::checkAmount(void)			const
{
	return (this->_amount);
}

void	Account::displayStatus(void)	const
{
	Account::_displayTimestamp();
	std::cout <<	"index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits <<
					";withdrawals:" << this->_nbWithdrawals << std::endl;
}
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout <<	"index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	return ;
}
//------------------------Non members---------------------------
void	Account::_displayTimestamp(void)
{
	std::tm		*s_time;
	std::time_t	current_time = std::time(NULL);

	s_time = std::localtime(&current_time);
	std::cout << 	"[" << s_time->tm_year + 1900  << std::setfill('0') <<
					std::setw(2) << s_time->tm_mon + 1 <<
					std::setw(2) << s_time->tm_mday << "_" <<
					std::setw(2) << s_time->tm_hour <<
					std::setw(2) << s_time->tm_min <<
					std::setw(2) << s_time->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout <<	"accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" <<
					Account::_totalNbDeposits << ";withdrawal:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;
