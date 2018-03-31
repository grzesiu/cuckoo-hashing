#include <stdlib.h>
#include <time.h>

template <typename T>
Cuckoo<T>::Cuckoo(int length) : length(length)
{
    array = new T[2 * length];
    srand(time(NULL));
    h1 = hash<T>(rand(), rand(), length);
    h2 = hash<T>(rand(), rand(), length);
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val)
{
    return insert(val, 0);
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val, int table) {}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::find(const T &val) const {}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::erase(iterator position) {}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::begin() {}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::end() {}

template <typename T>
const T &Cuckoo<T>::iterator::operator*() const
{
}

template <typename T>
const T *Cuckoo<T>::iterator::operator->() const
{
}

template <typename T>
typename Cuckoo<T>::iterator &Cuckoo<T>::iterator::operator++()
{
    i++;
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::iterator::operator++(int)
{
    iterator orig = *this;
    ++(*this);
    return orig;
}

template <typename T>
bool Cuckoo<T>::iterator::operator==(iterator const &other) const
{
    return i == other.i;
}

template <typename T>
bool Cuckoo<T>::iterator::operator!=(iterator const &other) const
{
    return !(*this == other);
}