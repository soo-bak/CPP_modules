#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Account.hpp"

Account::Account( int initial_deposit ) {
  _nbDeposits = initial_deposit;
}

Account::~Account( void ) {

}

void Account::displayAccountsInfos() {
  _displayTimestamp();
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
  std::stringstream stringStream;
  stringStream << "[" << thisYear;
  stringStream << std::setfill('0') << std::setw(2) << thisMonth;
  stringStream << std::setfill('0') << std::setw(2) << thisDay << "]";
  std::string timeStamp = stringStream.str();

  std::cout << timeStamp << std::endl;
}
