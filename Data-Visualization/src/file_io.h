#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

std::vector<int> readDataFromFile(const std::string& filename);
std::vector<std::string> readDataStringFromFile(const std::string& filename);
std::string getRandomString(int minLength, int maxLength);
#endif
