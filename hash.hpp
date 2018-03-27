#include <cstdint>

struct hash
{
  uint64_t a, b, m;

public:
  hash(uint64_t a, uint64_t b, uint64_t m);
  uint64_t operator()(uint64_t x) const;
  bool operator<(const hash &other) const;
};
