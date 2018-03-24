#include "bloom.hpp"

template <typename T>
Bloom<T>::Bloom(uint64_t size, uint8_t num_hashes) : size(size),
                                                     num_hashes(num_hashes) {}

template <typename T>
int Bloom<T>::get_size()
{
    return bs.size();
}