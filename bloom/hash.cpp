#include "hash.hpp"

hash::hash(uint64_t a, uint64_t b, uint64_t m) : a(a), b(b), m(m) {}

uint64_t hash::operator()(uint64_t x) const
{
    return (a * x + b) % m;
}

bool hash::operator<(const hash &other) const
{
    return other.a < a;
}