#include <../lib/json.hpp>
#include <string>

namespace fileIO{
  //using json as nlohmann for simplifying object creation
  using json = nlohmann::json;
  //reads data from already saved file and returns it as a json object
  json readJSON(const std::string& filename){

  }
}
