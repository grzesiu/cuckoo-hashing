#include "bloom.hpp"
#include <iostream>
#include <string>

int main() {
    Bloom<std::string> b;
    std::cout << b.h("awdoanwf");
    return 0;
}