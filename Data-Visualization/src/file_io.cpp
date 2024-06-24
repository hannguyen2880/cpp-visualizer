#include "file_io.h"
#include <fstream>
#include <sstream>

std::vector<int> readDataFromFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            data.push_back(value);
        }
    }

    return data;
}
