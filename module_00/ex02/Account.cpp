#include <chrono>

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
  std::chrono


}
