#include <set>
#include <deque>
#include <random>
#include <fstream>
#include <iostream>

int main()
{
    std::deque<int> items;
    std::set<int> items_set;

    while(items.size() < 110000)
    {
        int item = rand();
        if(items_set.find(item) == items_set.end())
        {
            items_set.insert(item);
            items.push_back(item);
        }
    }

    std::ofstream myfile;
    myfile.open("dataset");

    for (auto i : items)
    {
        myfile << i << std::endl;
    }
    
    myfile.close();

    return 0;
}