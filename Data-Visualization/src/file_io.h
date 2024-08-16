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

std::vector<int> readDataFromFile(const std::string& filename);
std::vector<std::string> readDataStringFromFile(const std::string& filename);
std::string getRandomString(int minLength, int maxLength);
std::unordered_map<int, std::list<int>> readGraphFromMatrixFile(const std::string& filename);
std::unordered_map<int, std::list<int>> readGraphFromAdjFile(const std::string& filename);
#endif
