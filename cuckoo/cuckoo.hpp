#include <algorithm>
#include <cstddef>
#include <vector>

#include "hash.hpp"

template <typename T>
class Cuckoo
{
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
  iterator insert(const T &val);
  iterator find(const T &val) const;
  iterator erase(iterator position);
  iterator begin();
  iterator end();

private:
  int length;
  T *items_list;
  bool *usage_list;
  hash<T> h1;
  hash<T> h2;
  iterator insert(const T &val, int table);
};

#include "cuckoo.tpp"