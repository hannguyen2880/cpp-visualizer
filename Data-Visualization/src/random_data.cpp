#include "random_data.h"
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomData(int size, int minValue, int maxValue) {
    std::vector<int> data(size);
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; ++i) {
        data[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }

    return data;
}
