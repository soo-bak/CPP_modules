#pragma once

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, const int& target) {
  const typename T::iterator& i(std::find(container.begin(), container.end(), target));
  return i;
}
