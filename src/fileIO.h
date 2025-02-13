#ifndef FILE_IO_H
#define FILE_IO_H

#include <../lib/json.hpp>

namespace fileIO {
using json = nlohmann::json;
//read json data from file and return it as an object
json readJSON(const std::string& filename);
}

#endif
