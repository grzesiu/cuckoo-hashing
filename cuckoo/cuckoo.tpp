#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
Cuckoo<T>::Cuckoo(int length, int num_hashes) : length(length), num_hashes(num_hashes)
{
    items_array = new T *[num_hashes];
    usage_array = new bool *[num_hashes];
    hashes_array = new hash<T>[num_hashes];

    srand(time(NULL));
    for (int i = 0; i < num_hashes; i++)
    {
        items_array[i] = new T[length];
        usage_array[i] = new bool[length];
        hashes_array[i] = hash<T>(rand(), rand(), length);
    }
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val)
{
    return insert(val, 0, 0);
}

template <typename T>
typename Cuckoo<T>::iterator Cuckoo<T>::insert(const T &val, const int array, const int count)
{
    if (count > num_hashes * length)
    {
        std::cout << "rehaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaashing" << std::endl;
    }
    else
    {
        int i = hashes_array[array](val);
        if (usage_array[array][i])
        {
            insert(items_array[array][i], (array + 1) % num_hashes, count + 1);
            items_array[array][i] = val;
        }
        else
        {
            items_array[array][i] = val;
            usage_array[array][i] = true;
        }
        return iterator(array, i);
    }
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
void Cuckoo<T>::print_arrays() const
{
    for (int n = 0; n < num_hashes; n++)
    {
        std::cout << n << std::endl;
        for (int i = 0; i < length; i++)
        {
            std::cout << items_array[n][i] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
Cuckoo<T>::iterator::iterator(int array, int i) : array(array), i(i) {}

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
    if (i == length)
    {
        i = 0;
        array = (array + 1) % num_hashes;
    }
    return *this;
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
