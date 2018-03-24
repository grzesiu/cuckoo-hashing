#include <functional>

template <typename T>
struct Bloom
{
    std::hash<T> h;
};