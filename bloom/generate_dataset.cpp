#include "constants.cpp"

#include <set>
#include <deque>
#include <random>
#include <fstream>
#include <iostream>

int main()
{
    std::deque<int> dataset_deque;
    std::set<int> dataset;

    while(dataset.size() < Constants::dataset_size + Constants::test_size)
    {
        int item = rand();
        if(dataset.find(item) == dataset.end())
        {
            dataset.insert(item);
            dataset_deque.push_back(item);
        }
    }

    std::ofstream dataset_file;
    dataset_file.open("dataset");

    for (auto i : dataset_deque)
    {
        dataset_file << i << std::endl;
    }

    dataset_file.close();

    return 0;
}
