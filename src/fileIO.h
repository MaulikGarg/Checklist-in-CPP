#ifndef FILE_IO_H
#define FILE_IO_H

#include "../lib/json.hpp"
#include <string>
#include <fstream>
#include <iostream>

namespace fileIO {
using json = nlohmann::json;
//read json data from file and return it as an object
void readJSON(json& data, const std::string& filename);
}

#endif
