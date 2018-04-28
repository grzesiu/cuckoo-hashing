template <typename T>
hash<T>::hash() {}

template <typename T>
hash<T>::hash(int a, int b, int m) : a(a), b(b), m(m) {}

template <typename T>
int hash<T>::operator()(const T &t) const
{
  return (a * h(t) + b) % m;
}
