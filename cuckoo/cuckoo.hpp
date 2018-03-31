#include <algorithm>
#include <cstddef>
#include <vector>

#include "hash.hpp"

template <typename T>
class Cuckoo
{
  int length;
  T *array;
  hash<T> h1;
  hash<T> h2;

public:
  class iterator : public std::iterator<std::input_iterator_tag,
                                        T, ptrdiff_t, const T *, const T &>
  {
    int i;

  public:
    const T &operator*() const;
    const T *operator->() const;
    iterator &operator++();
    iterator operator++(int);
    bool operator==(iterator const &other) const;
    bool operator!=(iterator const &other) const;
  };

  Cuckoo(int length);
  iterator begin();
  iterator end();
};

#include "cuckoo.tpp"