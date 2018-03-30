#include "cuckoo.hpp"

template <typename T>
Cuckoo<T>::Cuckoo(int length) : length(length) {
    array = new T[2 * length];
}

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