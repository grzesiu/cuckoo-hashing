#include "bloom.hpp"

#include <iostream>
#include <random>

template <typename T>
Bloom<T>::Bloom(uint64_t size, uint8_t num_hashes) : size(size),
                                                     num_hashes(num_hashes)
{
    while(hashes.size() < num_hashes)
    {
        int a = rand();
        int b = rand();
        hashes.insert(hash(a, b, size));
        std::cout << a << " " << b << " " << size << std::endl;
    }
}

template <typename T>
void Bloom<T>::add(const T &item)
{
    std::hash<T> h;
    uint64_t x = h(item);
    for (auto const &hash : hashes)
    {
        bs.set(hash(x), true);
    }
}

template <typename T>
bool Bloom<T>::can_contain(const T &item) const
{  
    std::hash<T> h;
    uint64_t x = h(item);
    for (auto const &hash : hashes)
    {
        if (!bs.test(hash(x)))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
boost::dynamic_bitset<> const& Bloom<T>::get_bs() const
{
    return bs;
}
