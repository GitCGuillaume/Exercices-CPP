/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:10:16 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/11 18:10:32 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>


/*
 * Variables non-member
 * video intra non-member Day0
*/

static int	account_index = 0;
int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = account_index;
	account_index++;
	Account::_nbAccounts = account_index;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t timer;
	struct tm *s_time;
	std::string	str;

	timer = time(NULL);
	s_time = localtime(&timer);
	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(2) << s_time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << s_time->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << s_time->tm_mday;
	std::cout << std::setfill('0') << "_" << std::setw(2) << s_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << s_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << s_time->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";" ;
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_amount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool is_valid = true;

	if (withdrawal > this->_amount)
		is_valid = false;
	else
	{
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	if (is_valid == false)
	{
		std::cout << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused";
	}
	else
	{
		std::cout << ";p_amount:" << this->_amount + withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	std::cout << std::endl;
	return (true);
}
