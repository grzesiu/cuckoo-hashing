#include <functional>
#include <boost/dynamic_bitset.hpp>

template <typename T>
struct Bloom
{
private:
  uint64_t size;
  uint8_t num_hashes;
  boost::dynamic_bitset<> bs{size};

public:
  Bloom(uint64_t size, uint8_t num_hashes);
  std::hash<T> h;
  int get_size();
};