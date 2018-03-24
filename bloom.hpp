#include <functional>

template <typename T>
struct Bloom
{
  private:
    uint64_t size;
    uint8_t num_hashes;

  public:
    Bloom(uint64_t size, uint8_t num_hashes);
    std::hash<T> h;
};