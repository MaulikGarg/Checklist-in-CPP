#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
#include "bossList.h"

namespace fileIO {
using json = nlohmann::json;

// read json data from file and return it as an object
void readJSON(json& data, const std::string& filename);

//writes the current mainlist to a file
void writeJSON(const std::map<std::string, List>& data,
               const std::string& filename);
}  // namespace fileIO

#endif
