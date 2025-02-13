#include "fileIO.h"

namespace fileIO {
// using json as nlohmann for simplifying object creation
using json = nlohmann::json;

// reads data from already saved file and returns it as a json object
void readJSON(json& data, const std::string& filename) {
  // make an input stream of the json file
  std::ifstream bossfile("../lists/" + filename + ".json");
  // check if the file opening failed
  if (!bossfile.is_open()) {
    std::cout << "Failed to open file ../lists/" << filename
              << ".json\n Starting with an empty list.\n";
    return;
  }
  // check if the file is empty
  if (bossfile.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Error: File is empty!\n";
    return;
  }
  // read data
  try {
    data = json::parse(bossfile);
  } catch (const json::parse_error& e) {
    std::cout << "Error: File is invalid!\n";
    return;
  }

  // close the now opened file as it is so no longer needed
  bossfile.close();
  std::cout << "Loaded lists from " << filename << " successfully.\n";
  return;
}

void writeJSON(const std::map<std::string, List>& data,
               const std::string& filename) {
  std::ofstream bossfile("../lists/" + filename + ".json");
  if (!bossfile.is_open()) {
    std::cout << "Writing to file " << filename << " failed. ";
    return;
  }
  json inData;
  for (const auto& [key, value] : data) {
    inData[key] = value.getList();
  }
  bossfile << inData;
  bossfile.close();
}
}  // namespace fileIO
