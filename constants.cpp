#include "constants.hpp"

#include <cmath>

const int Constants::filters_number = 5;
const int Constants::dataset_size = 1000000;
const int Constants::false_size = 100000;
const int Constants::filter_size = filters_number * dataset_size / std::log(2);
