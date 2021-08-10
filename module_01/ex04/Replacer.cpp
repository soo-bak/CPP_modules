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
  std::string fileContents(_parseFileContents());
  if (_enableReplace(fileContents) == false) {
    _printMessage("<Error> There is nothing to replace.");
    exit(0);
  }
  std::size_t position(fileContents.find(_oldString));
  while (position != std::string::npos) {
    fileContents.erase(position, _oldString.size());
    fileContents.insert(position, _newString);
    position = fileContents.find(_oldString, position + _newString.size());
  }
  const std::string outFilename(_filename + ".replace");
  std::ofstream outFileStream(outFilename.c_str());
  outFileStream << fileContents;
  _printMessage("<Success> Replacement is complete.");
  return ;
}

void Replacer::_printMessage(const std::string& message) {
  const std::string colorRed("\033[1;31m");
  const std::string colorCyan("\033[1;36m");
  const std::string colorEnd("\033[0m");
  std::string colorStart;
  if (message.find("Error") != std::string::npos) {
    colorStart = colorRed;
  } else {
    colorStart = colorCyan;
  }
  std::cout << colorStart;
  std::cout << message << std::endl;
  std::cout << colorEnd;
  return ;
}

const std::string Replacer::_parseFileContents(void) const {
  std::ifstream inputFileStream(_filename.c_str());
  if (!inputFileStream) {
    _printMessage("<Error> Can not open the file.");
    exit(0);
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

bool Replacer::_enableReplace(const std::string& fileContents) const {
  if (_oldString.compare(_newString) == 0) {
    return false;
  } else if (fileContents.find(_oldString) == std::string::npos) {
    return false;
  } else {
    return true;
  }
}
