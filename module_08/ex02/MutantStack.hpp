#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

  public:

    class iterator {

      public:

        iterator& operator ++ () {_pointer++; return *this;}
        iterator operator ++ (int) {
          iterator temp(*this);
          ++*this;
          return temp;
        }
        iterator& operator -- () {_pointer--; return *this;}
        iterator operator -- (int) {
          iterator temp(*this);
          --*this;
          return temp;
        }

        iterator& operator = (const iterator& other) {
          if (this == &other) {
            return *this;
          }
          _pointer = other._pointer;
          return *this;
        }

        iterator& operator - (int number) {
          _pointer -= number;
          return *this;
        }

        iterator& operator + (int number) {
          _pointer += number;
          return *this;
        }

        bool operator == (const iterator& rightSideHand) {
          return _pointer == rightSideHand._pointer;
        }
        bool operator != (const iterator& rightSideHand) {
          return _pointer != rightSideHand._pointer;
        }
        bool operator < (const iterator& rightSideHand) {
          return _pointer < rightSideHand._pointer;
        }
        bool operator > (const iterator& rightSideHand) {
          return _pointer > rightSideHand._pointer;
        }
        bool operator >= (const iterator& rightSideHand) {
          return _pointer >= rightSideHand._pointer;
        }
        bool operator <= (const iterator& rightSideHand) {
          return _pointer <= rightSideHand._pointer;
        }
        T& operator * () {return *_pointer;}

        iterator(void) {}
        iterator(const iterator& other) {*this = other;}
        iterator(T* pointerInput) : _pointer(pointerInput) {}
        ~iterator() {}

      private:
        T* _pointer;
    };

    MutantStack<T>& operator = (const MutantStack<T>& other) {
      std::stack<T>::operator = (other);
      return *this;
    }

    MutantStack<T>(void) {}
    MutantStack<T>(const MutantStack& other) {*this = other;}
    ~MutantStack<T>() {}

    iterator begin(void) {
      T* bottom = &std::stack<T>::top() - (std::stack<T>::size() - 1);
      return iterator(bottom);
    }
    iterator end(void) {
      T* top = &std::stack<T>::top();
      return iterator(top + 1);
    }
};
