#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "raylib.h"
#include <unordered_map>
#include <list>
#include "DataStructures//Graph/Graph.h"

std::vector<int> readDataFromFile(const std::string& filename);
std::vector<std::string> readDataStringFromFile(const std::string& filename);
std::string getRandomString(int minLength, int maxLength);
void readGraphFromMatrixFile(const std::string& filename, Graph& graph);
#endif
