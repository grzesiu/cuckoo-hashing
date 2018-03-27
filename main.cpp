#include "bloom.tpp"
#include <iostream>
#include <string>

int main()
{
    Bloom<std::string> b(10, 5);
    b.add("hello");
    std::cout << b.get_bs() << std::endl;
    b.add("awd");
    std::cout << b.get_bs() << std::endl;
    b.add("hello");
    std::cout << b.get_bs() << std::endl;
    return 0;
}