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
    static void _printMessage(const std::string& message);

    const std::string _filename;
    const std::string _oldString;
    const std::string _newString;

    const std::string _parseFileContents(void) const;
    bool _enableReplacement(const std::string& fileContents) const;
};
