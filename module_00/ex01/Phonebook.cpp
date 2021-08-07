#include "Phonebook.hpp"

Phonebook::Phonebook()
 : _columnWidth(10), _phonebookSize(8),
   _registeredNumber(0), _indexToAdd(0), _selectedIndex(0) {
}

Phonebook::~Phonebook() {
}

void Phonebook::openPhonebook() {
  std::cout << "Enter the command : ";
  std::string input;
  std::getline(std::cin, input).eof();
  if (std::cin.bad() || std::cin.eof())
    exit(0);
  const unsigned int command(_makeCommandValue(input));
  _executeCommand(command);
  return ;
}

unsigned int Phonebook::_makeCommandValue(const std::string& input) {
  unsigned int commandValue(0);
  if (input.compare("ADD") == 0) {
    commandValue |= Add;
  } else if (input.compare("SEARCH") == 0) {
    commandValue |= Search;
  } else if (input.compare("EXIT") == 0) {
    commandValue |= Exit;
  } else if (input.empty()) {
    commandValue |= Empty;
  } else {
    commandValue |= Error;
  }
  return commandValue;
}

const std::string Phonebook::_makeTruncatedString(std::string& stringInput) const{
  if (stringInput.size() > static_cast<size_t>(_columnWidth)) {
    const std::size_t truncatedIndex(_columnWidth - 1);
    stringInput.at(truncatedIndex) = '.';
    const std::size_t truncatedSize(truncatedIndex + 1);
    stringInput.resize(truncatedSize);
  }
  return stringInput;
}

void Phonebook::_displayContactList() const {
  for (int row = 0; row < _registeredNumber + 1; row++) {
    std::stringstream listStream;
    listStream << "|";
    for (int column = 0; column <= Contact::NickName + 1; column++) {
      std::string content;
      if (row == 0 && column == 0) {
        content = "Index";
      } else if (row == 0 && column > 0) {
        content = Contact::getFieldNameArray()[column - 1];
      } else if (row > 0 && column == 0) {
        content = _contact[row - 1].getContactIndex();
      } else if (row > 0 && column > 0) {
        content = _contact[row - 1].getInformationArray()[column - 1];
      }
      _makeTruncatedString(content);
      listStream << std::setw(_columnWidth) << std::right;
      listStream << content << "|";
    }
    listStream << std::endl;
    std::cout << listStream.str();
  }
  return ;
}

void Phonebook::_displayContactInformation() const {
  const int startZeroIndex(_selectedIndex - 1);
  _contact[startZeroIndex].printInformation();
}

void Phonebook::_executeCommand(const unsigned int& command) {
  if (command & Add) {
    _addContact();
  } else if (command & Search) {
    _searchContact();
  } else if (command & Exit) {
    exit(0);
  } else if (command & Error) {
    std::cout << "It's wrong command, try again." << std::endl;
  }
  return ;
}

void Phonebook::_addContact() {

  _contact[_indexToAdd].makeInformation();
  _contact[_indexToAdd].setContactIndex(_indexToAdd);
  _indexToAdd++;
  _registeredNumber++;
  if (_indexToAdd >= _phonebookSize)
    _indexToAdd = 0;
  if (_registeredNumber >= _phonebookSize)
    _registeredNumber = _phonebookSize;
  return ;
}

void Phonebook::_searchContact() {
  if (_registeredNumber == 0) {
      std::cout << "No contacts are registered." << std::endl;
      return ;
  }
  _displayContactList();
  _selectContact();
  _displayContactInformation();
  return ;
}

void Phonebook::_selectContact() {
  std::cout << "Select the index to detail information." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  if (std::cin.bad() || std::cin.eof())
    exit(0);
  _selectedIndex = atoi(input.c_str());
  if (_selectedIndex > _registeredNumber || _selectedIndex < 1) {
    std::cout <<  "The index is invalid, try again." << std::endl;
    _selectContact();
  }
  return ;
}
