#include <iostream>
#include <string>

#include "MutantStack.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {
  std::cout << " [ " << ansiPurple << "Test Inherited functions" << ansiEnd << " ]" << std::endl;
  MutantStack<int> mstack;
  const int maxSize = 5;
  for (int i = 1; i < maxSize + 1; i++) {
    mstack.push(i);
    std::cout << "   mstack.push(" << ansiCyan << i << ansiEnd << ") excuted" << std::endl;
  }
  std::cout << std::endl;

  std::cout << "   mstack.top() : ";
  std::cout << ansiCyan << mstack.top() << ansiEnd << std::endl;
  std::cout << std::endl;

  mstack.pop();
  std::cout << "   mstack.pop() excuted" << std::endl;
  std::cout << "   mstack.top() : ";
  std::cout << ansiCyan << mstack.top() << ansiEnd << std::endl;
  std::cout << "   mstack.size() : ";
  std::cout << ansiYellow << mstack.size() << ansiEnd << std::endl;
  std::cout << std::endl;

  mstack.push(42);
  std::cout << "   mstack.push(" << ansiCyan << 42 << ansiEnd << ") excuted" << std::endl;
  mstack.push(4242);
  std::cout << "   mstack.push(" << ansiCyan << 4242 << ansiEnd << ") excuted" << std::endl;
  mstack.push(424242);
  std::cout << "   mstack.push(" << ansiCyan << 424242 << ansiEnd << ") excuted" << std::endl;
  std::cout << std::endl;

  std::cout << " [ " << ansiPurple << "Test iterator operation" << ansiEnd << " ]" << std::endl;  std::cout << "   mstack.begin() : " << ansiCyan;
  std::cout << *mstack.begin() << ansiEnd << std::endl;
  std::cout << "   mstack.end() - 1 : " << ansiCyan;
  std::cout << *(mstack.end() - 1) << ansiEnd << std::endl;
  //[...]

  MutantStack<int>::iterator it = mstack.begin();
  std::cout << "   it = mstack.begin()" << std::endl;
  std::cout << "   *(it++) : " << *(it++) << std::endl;
  std::cout << "   *(it--) : " << *(it--) << std::endl;
  std::cout << "   *it : " << *it << std::endl;
  MutantStack<int>::iterator ite = mstack.end();
  std::cout << "   ite = mstack.end()" << std::endl;
  std::cout << "   *(--ite) : " << *(--ite) << std::endl;
  std::cout << "   *(++ite) : " << *(++ite) << std::endl;
  std::cout << "   *ite : " << *ite << std::endl;

  std::cout << " [ " << ansiPurple << "mstack.end() test" << ansiEnd << " ]" << std::endl;
  while (it != ite)
  {
    std::cout << ansiCyan << "   " << *it << ansiEnd <<std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << "        s.top() : ";
  std::cout << ansiCyan << s.top() << ansiEnd << std::endl;
  std::cout << "   mstack.top() : ";
  std::cout << ansiCyan << mstack.top() << ansiEnd << std::endl;

  return 0;
}
