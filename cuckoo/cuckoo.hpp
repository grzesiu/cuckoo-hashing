#include <algorithm>
#include <cstddef>

template <typename T>
class Cuckoo
{
  int size;

public:
  class iterator : public std::iterator<std::input_iterator_tag,
                                        T, ptrdiff_t, const T *, const T &>

  {

  public:
    const T &operator*() const;
    const T *operator->() const;
    iterator &operator++();
    iterator operator++(int);
    bool operator==(iterator const &other) const;
    bool operator!=(iterator const &other) const;
  };

  Cuckoo(int size);
  iterator begin();
  iterator end();
};