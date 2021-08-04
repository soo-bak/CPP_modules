#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Account.hpp"

int Account::_nbAccounts = 1;

Account::Account( int initial_deposit ) {
  _amount = initial_deposit;
  _accountIndex = _nbAccounts - 1;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";" << "created" << std::endl;
  _nbAccounts++;
}

Account::~Account( void ) {

}

void Account::displayAccountsInfos() {
}

void Account::displayStatus( void ) const {

};

void Account::makeDeposit( int deposit ) {
  _nbDeposits = deposit;
}

bool Account::makeWithdrawal( int withdrawal ) {
  _nbWithdrawals = withdrawal;
  return true;
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
