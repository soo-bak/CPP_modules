#pragma once

template <typename T>
void swap(T& first, T& second) {
  T temp(first);
  first = second;
  second = temp;
  return ;
}

template <typename T>
const T& min(const T& first, const T& second) {
  if (first < second) {
    return first;
  }
  return second;
}

template <typename T>
const T& max(const T& first, const T& second) {
  if (first > second) {
    return first;
  }
  return second;
}
