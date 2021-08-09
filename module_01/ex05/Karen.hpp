#include <iostream>
#include <string>

class Karen {
  public:
    Karen(void);
    ~Karen(void);

    void complain(std::string level);

  private:
    enum Level {
      Debug,
      Info,
      Warning,
      Error
    };

    static const std::string _validLevels[4];

    void (Karen::*_levelFunctions[4])(void);

    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};
