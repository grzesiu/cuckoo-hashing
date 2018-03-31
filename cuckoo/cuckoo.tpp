#include <stdlib.h>
#include <time.h>

template <typename T>
Cuckoo<T>::Cuckoo(int length, int num_hashes) : length(length), num_hashes(num_hashes)
{
    items_array = new T[num_hashes * length];
    usage_array = new bool[num_hashes * length];
    hashes_array = new hash<T>[num_hashes];
    srand(time(NULL));
    for (int i = 0; i < num_hashes; i++)
    {
        hashes_array[i] = hash<T>(rand(), rand(), length);
    }
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val)
{
    return insert(val, 0);
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val, int array)
{
    int i = hashes_array[array](val);
    if (usage_array[i])
    {
        insert(items_array[i], (array++) % num_hashes);
        items_array[i] = val;
    }
    else
    {
        items_array[i] = val;
        usage_array[i] = true;        
    }
    return iterator(i);
}

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