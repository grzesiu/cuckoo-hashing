#include <functional>

template <typename T>
class hash
{
  int a, b, m;
  std::hash<T> h;

public:
  hash();
  hash(int a, int b, int m);
  int operator()(const T &t) const;
};

#include "hash.tpp"