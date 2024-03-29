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
        int array, i;

        public:
        iterator(int array, int i);
        const T &operator*() const;
        const T *operator->() const;
        iterator &operator++();
        iterator operator++(int);
        bool operator==(iterator const &other) const;
        bool operator!=(iterator const &other) const;
    };

        Cuckoo(int length, int num_hashes);
        iterator insert(const T &val);
        iterator find(const T &val) const;
        iterator erase(iterator position);
        iterator begin();
        iterator end();
        void print_arrays() const;

    private:
        int length, num_hashes;
        T **items_array;
        bool **usage_array;
        hash<T> *hashes_array;
        iterator insert(const T &val, const int array, const int count);
        void rehash();
};

#include "cuckoo.tpp"
