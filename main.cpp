#include "bloom.tpp"
#include <iostream>
#include <string>

int main() {
    Bloom<std::string> b(10, 5);
    std::cout << b.get_size();
    return 0;
}