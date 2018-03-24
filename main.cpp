#include "bloom.tpp"
#include <iostream>
#include <string>

int main() {
    Bloom<std::string> b(10, 5);
    std::cout << b.h("awdoanwf");
    return 0;
}