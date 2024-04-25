#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Private
void	Account::_displayTimestamp( void ) {
	time_t	timer;
	struct	tm	*curr_time;
	char	buffer[18];
	std::string	timestamp;

	time(&timer);
	curr_time = localtime(&timer);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", curr_time);
	timestamp.assign(buffer);
	std::cout << timestamp;
}

// Getters
int	Account::getNbAccounts( void ) {
	return 0;
}

int	Account::getTotalAmount( void ) {
	return 0;
}

int	Account::getNbDeposits( void ) {
	return 0;
}

int	Account::getNbWithdrawals( void ) {
	return 0;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructeur et destructeur
Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"<< initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Setters
void	Account::makeDeposit( int deposit ) {
	int	old_amount;

	old_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << old_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout <<  " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	
	if (_amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return false;
	}
	else {	
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const {
	return 0;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}