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
  std::cout << timeStamp << std::endl;
}
