#include "file_io.h"

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

std::vector<std::string> readDataStringFromFile(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string value;
        while (iss >> value) {
            data.push_back(value);
        }
    }

    return data;
}

std::string getRandomString(int minLength, int maxLength) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int nLen = GetRandomValue(minLength, maxLength);
    std::string data = "";
    for (int i = 0; i < nLen; ++i) {
        int index = GetRandomValue(0, 52);
        data.push_back(characters[index]);
    }
    return data;
}

void readGraphFromMatrixFile(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);
    int n;
    file >> n;
    for (int i = 1; i <= n; ++i) {
        graph.vertices.insert(i);
        for (int j = 1; j <= n; ++j) {
            int x;
            file >> x;
            if (x > 0) {
                graph.adjList[i].push_back({ x, j });
                graph.adjList[j].push_back({ x, i });
            }
        }
    }
}