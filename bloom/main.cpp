#include "bloom.tpp"

#include "constants.cpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

int main()
{
    Bloom<int> bloom(Constants::filter_size, Constants::num_hashes);

    std::ifstream dataset_file;
    dataset_file.open("dataset");

    int item;

    for(int i = 0; i < Constants::dataset_size; i++)
    {
        dataset_file >> item;
        bloom.add(item);
    }

    dataset_file.clear();
    dataset_file.seekg(0, std::ios_base::beg);

    int fp = 0;
    int tp = 0;

    for(int i = 0; i < Constants::dataset_size; i++)
    {
        dataset_file >> item;
        tp += bloom.can_contain(item);
    }

    int i = 0;
    for(; i < Constants::test_size; i++)
    {
        dataset_file >> item;
        fp += bloom.can_contain(item);
    }

    std::cout << i << std::endl;
    std::cout << Constants::filter_size;
    dataset_file.close();

    std::cout << "tp: " << tp << std::endl;
    std::cout << "fp: " << fp << std::endl;

    return 0;
}
