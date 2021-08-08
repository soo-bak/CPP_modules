#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

class Replacer {
  public:

    Replacer(const std::string& filenameInput,
             const std::string& oldStringInput,
             const std::string& newStringInput);
    ~Replacer(void);

    void makeReplacedFile(void) const;

  private:

    const std::string _filename;
    const std::string _oldString;
    const std::string _newString;

    std::string _parseFileContents(void) const;


};
