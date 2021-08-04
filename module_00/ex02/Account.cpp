#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
  : _accountIndex(_nbAccounts), _amount(initial_deposit) {
    _totalAmount += _amount;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";" << "created" << std::endl;
  _nbAccounts++;
}

Account::~Account( void ) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "closed" << std::endl;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts << ";";
  std::cout << "total:" << _totalAmount << ";";
  std::cout << "deposits:" << _totalNbDeposits << ";";
  std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

void Account::displayStatus( void ) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
};

void Account::makeDeposit( int deposit ) {
  const int p_amount = _amount;
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
  bool isSucceeded = false;
  const int p_amount = _amount;
  std::stringstream withdrawalStream;
  if (_amount >= withdrawal) {
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    withdrawalStream << withdrawal << ";";
    withdrawalStream << "amount:" << _amount << ";";
    withdrawalStream << "nb_withdrawals:" << _nbWithdrawals;
    isSucceeded = true;
  } else {
    withdrawalStream << "refused";
  }
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "withdrawal:" << withdrawalStream.str() << std::endl;
  return isSucceeded;
}

void Account::_displayTimestamp() {
  time_t timer = time(NULL);
  tm *localTimer = localtime(&timer);
  const int thisYear = 1900 + localTimer->tm_year;
  const int thisMonth = 1 + localTimer->tm_mon;
  const int thisDay = localTimer->tm_mday;
  const int thisHour = localTimer->tm_hour;
  const int thisMinute = localTimer->tm_min;
  const int thisSecond = localTimer->tm_sec;
  std::stringstream stringStream;
  stringStream << "[" << thisYear;
  stringStream << std::setfill('0') << std::setw(2) << thisMonth;
  stringStream << std::setfill('0') << std::setw(2) << thisDay << "_";
  stringStream << std::setfill('0') << std::setw(2) << thisHour;
  stringStream << std::setfill('0') << std::setw(2) << thisMinute;
  stringStream << std::setfill('0') << std::setw(2) << thisSecond << "]";
  const std::string timeStamp = stringStream.str();
  std::cout << timeStamp;
}
