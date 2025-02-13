#include "fileIO.h"

namespace fileIO {
// using json as nlohmann for simplifying object creation
using json = nlohmann::json;

// reads data from already saved file and returns it as a json object
void readJSON(json& data, const std::string& filename) {
  // make an input stream of the json file
  std::ifstream bossfile("../lists/" + filename + ".json");
  // check if the file opening failed
  if (!bossfile.good()) {
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
  data = json::parse(bossfile);
  bossfile.close();
  std::cout << "Loaded lists from " << filename << " successfully.\n";
  return;
}
}  // namespace fileIO
