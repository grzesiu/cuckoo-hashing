#include <set>
#include <functional>
#include <boost/dynamic_bitset.hpp>
#include "hash.cpp"

template <typename T>
struct Bloom
{
private:
  uint64_t size;
  uint8_t num_hashes;
  boost::dynamic_bitset<> bs{size};
  std::set<hash> hashes;

public:
  Bloom(uint64_t size, uint8_t num_hashes);

  void add(const T &item);

  bool can_contain(const T &item) const;

  boost::dynamic_bitset<> const& get_bs() const;

};
