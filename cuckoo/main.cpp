#include <iostream>
#include <functional>
#include <vector>

#include "cuckoo.hpp"

void test_insert(Cuckoo<int> &c)
{
    std::vector<int> test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : test)
    {
        c.print_arrays();
        std::cout << "insert: " << i << std::endl;
        c.insert(i);
    }
    c.print_arrays();
}

int main()
{
    Cuckoo<int> c(6, 2);
    test_insert(c);
    return 0;
}