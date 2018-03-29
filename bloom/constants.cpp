#include "constants.hpp"

#include <iostream>
#include <cmath>

const int Constants::num_hashes = 5;
const int Constants::dataset_size = 1000000;
const int Constants::test_size = 100000;
const int Constants::filter_size = num_hashes * dataset_size / std::log(3);
