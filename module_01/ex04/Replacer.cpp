#include "Replacer.hpp"

Replacer::Replacer(const std::string& filenameInput,
                   const std::string& oldStringInput,
                   const std::string& newStringInput)
 : _filename(filenameInput), _oldString(oldStringInput),
   _newString(newStringInput) {
}

Replacer::~Replacer(void) {
}

void Replacer::makeReplacedFile(void) const {
  if (_oldString.compare(_newString) == 0) {
    std::cout << "There is nothing to replace." << std::endl;
    return ;
  }
  std::string fileContents(_parseFileContents());
  std::size_t position(fileContents.find(_oldString));
  while (position != std::string::npos) {
    fileContents.erase(position, _oldString.size());
    fileContents.insert(position, _newString);
    position = fileContents.find(_oldString, position + _newString.size());
  }
  std::cout << fileContents;
}

std::string Replacer::_parseFileContents(void) const {
  std::ifstream inputFileStream(_filename.c_str());
  if (!inputFileStream) {
    std::cerr << "Filename is wrong." << std::endl;
    exit(1);
  }
  std::string contents;
  while (!inputFileStream.eof()) {
    std::string line;
    getline(inputFileStream, line);
    contents.append(line + "\n");
  }
  const std::string::iterator lastNewline(contents.end() - 1);
  contents.erase(lastNewline);
  return contents;
}