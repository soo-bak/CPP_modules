#pragma once

#include <exception>

template <typename T>
class Array {

  public:

    Array& operator = (const Array& other) {
      if (this == &other) {
        return *this;
      }
      delete[] _elements;
      _copyInitialize(other);
      return *this;
    }

    T& operator [] (const unsigned int& index) {
      if (index >= _length) {
        throw std::exception();
      }
      return _elements[index];
    }

    Array(void) : _length(0), _elements(new T[_length]) {}
    Array(unsigned int n) : _length(n), _elements(new T[_length]) {}
    Array(const Array& other) {_copyInitialize(other);}
    ~Array() {delete[] _elements;}

    const unsigned int& size(void) const {return _length;}

  private:

    unsigned int _length;
    T* _elements;

    void _copyInitialize(const Array& other) {
      _length = other._length;
      _elements = new T[_length]();
      for (unsigned int i = 0; i < _length; i++) {
        _elements[i] = other._elements[i];
      }
      return ;
    }
};
