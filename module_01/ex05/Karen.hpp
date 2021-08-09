#include <iostream>
#include <string>
#include <stdlib.h>

class Karen {
  public:
    Karen(void);
    ~Karen(void);

    void complain(std::string levelInput);

  private:
    enum Levels {
      Debug = 'D',
      Info = 'I',
      Warning = 'W',
      Error = 'E'
    };


    static const std::string _level[4];

    void (Karen::*_levelFunction)(void);
    // void (Karen::*_levelFunction[4])(void);

    void _setLevelFunction(std::string& levelInput);
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};
