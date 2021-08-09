#include <iostream>
#include <string>
#include <stdlib.h>

class Karen {
  public:
    Karen(void);
    ~Karen(void);

    void complain(std::string levelInput);

  private:
    enum Level {
      Debug,
      Info,
      Warning,
      Error,
    };

    static const std::string _validLevels[4];

    void (Karen::*_levelFunction[4])(void);

    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};
